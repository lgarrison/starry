/**
Keplerian star/planet/moon system class.

TODO: `getflux()` is simply

        if (L != 0) flux_ += L * flux(theta(time), xo, yo, ro) - totalflux;

*/

#ifndef _STARRY_ORBITAL_H_
#define _STARRY_ORBITAL_H_

#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <string>
#include <vector>
#include "errors.h"
#include "maps.h"
#include "utils.h"
#include "rotation.h"

namespace units {

    const double DayToSeconds = 86400.0;

}; // namespace units

namespace kepler {

    using namespace utils;


    /* ---------------- */
    /*     FUNCTIONS    */
    /* ---------------- */

    /**
    Compute the eccentric anomaly. Adapted from
    https://github.com/lkreidberg/batman/blob/master/c_src/_rsky.c

    */
    template <typename T>
    T EccentricAnomaly(T& M, T& ecc) {
        // Initial condition
        T E = M;
        T tol = 10 * mach_eps<T>();
        if (ecc > 0) {
            // Iterate
            for (int iter = 0; iter <= STARRY_KEPLER_MAX_ITER; iter++) {
                E = E - (E - ecc * sin(E) - M) / (1. - ecc * cos(E));
                if (abs(E - ecc * sin(E) - M) <= tol) return E;
            }
            // Didn't converge!
            throw errors::ConvergenceError("The Kepler solver did not converge.");
        }
        return E;
    }

    /**
    Manual override of the derivative of the eccentric anomaly

    */
    template <typename T>
    Eigen::AutoDiffScalar<T> EccentricAnomaly(const Eigen::AutoDiffScalar<T>& M,
        const Eigen::AutoDiffScalar<T>& ecc) {
        typename T::Scalar M_value = M.value(),
                           ecc_value = ecc.value(),
                           E_value = EccentricAnomaly(M_value, ecc_value),
                           cosE_value = cos(E_value),
                           sinE_value = sin(E_value),
                           norm1 = 1./ (1. - ecc_value * cosE_value),
                           norm2 = sinE_value * norm1;
        if (M.derivatives().size() && ecc.derivatives().size())
            return Eigen::AutoDiffScalar<T>(E_value,
                                            M.derivatives() * norm1 +
                                            ecc.derivatives() * norm2);
        else if (M.derivatives().size())
            return Eigen::AutoDiffScalar<T>(E_value, M.derivatives() * norm1);
        else if (ecc.derivatives().size())
            return Eigen::AutoDiffScalar<T>(E_value, ecc.derivatives() * norm2);
        else
            return Eigen::AutoDiffScalar<T>(E_value, M.derivatives());
    }


    /* ---------------- */
    /*       BODY       */
    /* ---------------- */

    /**
    Generic body class, a subclass of Map with added orbital features.

    */
    template <class T>
    class Body : public maps::Map<T> {

        protected:

            // Hide the Map's flux function from the user,
            // as we compute lightcurves via the System class
            Row<T> flux();

            // Shorthand for the scalar type (double, Multi)
            using S = Scalar<T>;

            S r;                                                                /**< Body radius in units of primary radius */
            S L;                                                                /**< Body luminosity in units of primary luminosity */
            S prot;                                                             /**< Body rotation period in seconds */
            S tref;                                                             /**< Reference time in seconds */

            S theta0;                                                           /**< Body initial rotation angle in radians */
            S angvelrot;                                                        /**< Body rotational angular velocity in radians / second */
            S z0;                                                               /**< Reference point for retarded time calculation (the primary, assuming massless secondaries) */
            S dt_;                                                              /**< The light travel time delay in seconds */


            // Map attributes we need access to within this class
            using maps::Map<T>::lmax;
            using maps::Map<T>::N;
            using maps::Map<T>::nwav;

            // Private methods
            inline S theta(const S& time);
            void reset();

            //! Constructor
            explicit Body(int lmax=2, int nwav=1) :
                // Call the `Map` constructor
                maps::Map<T>(lmax, nwav) {

                // Set the orbital variables to default values
                setR(1.0);
                setL(1.0);
                setPRot(0.0);
                setTRef(0.0);
                reset();
            }

        public:

            // I/O
            void setR(const S& r_);
            S getR() const;
            void setL(const S& L_);
            S getL() const;
            void setPRot(const S& prot_);
            S getPRot() const;
            void setTRef(const S& tref_);
            S getTRef() const;

    };


    /* ---------------------- */
    /*    BODY: OPERATIONS    */
    /* ---------------------- */

    //! Re-compute orbital variables
    template <class T>
    void Body<T>::reset() {

        // Angular velocity
        angvelrot = (2 * pi<Scalar<T>>()) / prot;

        // Light travel time delay parameters.
        // Overriden by subclasses.
        z0 = 0;
        dt_ = 0;

        // Initial map rotation angle
        // Overriden by subclasses.
        theta0 = 0;

    };

    //! Rotation angle as a function of (retarded) time
    template <class T>
    inline Scalar<T> Body<T>::theta(const Scalar<T>& time) {
        if (prot == INFINITY)
            return theta0;
        else
            return mod2pi(theta0 + angvelrot * (time - tref - dt_));
    }


    /* ------------------ */
    /*     BODY: I/O      */
    /* ------------------ */

    //! Set the body's radius
    template <class T>
    void Body<T>::setR(const Scalar<T>& r_) {
        if (r_ > 0) r = r_;
        else throw errors::ValueError("Body's radius must be positive.");
    }

    //! Get the body's radius
    template <class T>
    Scalar<T> Body<T>::getR() const {
        return r;
    }

    //! Set the body's luminosity
    template <class T>
    void Body<T>::setL(const Scalar<T>& L_) {
        if (L_ > 0) L = L_;
        else throw errors::ValueError("Body's luminosity must be positive.");
    }

    //! Get the body's luminosity
    template <class T>
    Scalar<T> Body<T>::getL() const {
        return L;
    }

    //! Set the body's rotation period
    template <class T>
    void Body<T>::setPRot(const Scalar<T>& prot_) {
        if (prot_ > 0) prot = prot_ * units::DayToSeconds;
        else if (prot_ == 0) prot = INFINITY;
        else throw errors::ValueError("Body's rotation period must be positive.");
    }

    //! Get the body's rotation period
    template <class T>
    Scalar<T> Body<T>::getPRot() const {
        return prot / units::DayToSeconds;
    }

    //! Set the reference time
    template <class T>
    void Body<T>::setTRef(const Scalar<T>& tref_) {
        tref = tref_ * units::DayToSeconds;
    }

    //! Get the reference time
    template <class T>
    Scalar<T> Body<T>::getTRef() const {
        return tref / units::DayToSeconds;
    }


    /* ---------------- */
    /*     PRIMARY      */
    /* ---------------- */

    /**
    Primary class, a subclass of Body that simply sits
    quietly at the origin.

    */
    template <class T>
    class Primary : public Body<T> {

        public:

            //! Constructor
            explicit Primary(int lmax=2, int nwav=1) :

                // Call the `Body` constructor
                Body<T>(lmax, nwav) {

            }

    };

}; // namespace kepler

#endif
