/**
Instantiate a temporal map and compute the flux
during an occultation.

*/

#ifndef _TEST_TEMPORAL_H_
#define _TEST_TEMPORAL_H_

#include "test.h"

namespace test_temporal {

    /**
    Compare the flux in double precision to
    the flux using multiprecision.

    */
    int test_flux(int nb=100) {

        using namespace starry2;

        // Instantiate a temporal map with 3 time columns
        int lmax = 2;
        int nt = 3;
        Map<Temporal<double>> map(lmax, nt);
        
        // Give the star a time-variable total flux
        Vector<double> y00(nt);
        y00 << 1.0, -0.5, 0.25;
        map.setY(0, 0, y00);

        // Set the linear and quadratic
        // limb darkening coefficients;
        // these are constant in time
        map.setU(1, 0.4);
        map.setU(2, 0.26);

        // Compute the flux at t = 0.5, but for a varying
        // impact parameter
        double t = 0.5;
        Vector<double> b(nb); 
        b = Vector<double>::LinSpaced(nb, -1.5, 1.5);
        Vector<double> flux(nb);
        for (int i = 0; i < nb; ++i)
            map.computeFlux(t, 0.0, b(i), 0.0, 0.1, flux.row(i));

        // -- Compare to a static map --

        // At time t, the y00 coefficient should be...
        double y00t = y00(0) + y00(1) * t + 0.5 * y00(2) * t * t;

        // Let's check that we get the same flux from a static map:
        Map<Default<double>> map_static(lmax);
        map_static.setY(0, 0, y00t);
        map_static.setU(1, 0.4);
        map_static.setU(2, 0.26);
        Vector<double> flux_static(nb);
        for (int i = 0; i < nb; ++i)
            map_static.computeFlux(0.0, b(i), 0.0, 0.1, flux_static.row(i));

        // -- Now evaluate stuff in multiprecision --

        // Instantiate the default map
        Map<Temporal<Multi>> map_multi(lmax, nt);
        
        // Give the star unit flux
        map_multi.setY(0, 0, y00.template cast<Multi>());

        // Set the linear and quadratic
        // limb darkening coefficients
        map_multi.setU(1, 0.4);
        map_multi.setU(2, 0.26);

        // Compute the flux
        Vector<Multi> flux_multi(nb);
        for (int i = 0; i < nb; ++i)
            map_multi.computeFlux(Multi(t), 0.0, Multi(b(i)), 0.0, 0.1, flux_multi.row(i));

        // Compare
        int nerr = 0;
        if (!flux.isApprox(flux_static.template cast<double>())) {
            std::cout << "Flux does not match static flux in `test_flux`." << std::endl;
            ++nerr;
        }
        if (!flux.isApprox(flux_multi.template cast<double>())) {
            std::cout << "Flux does not match Multi flux in `test_flux`." << std::endl;
            ++nerr;
        }
        return nerr;
    }

    /**
    Compare the flux in double precision to
    the flux using multiprecision. Also
    compute and compare derivatives.

    */
    int test_flux_with_grad(int nb=100) {

        using namespace starry2;

        // Instantiate a temporal map with 3 time columns
        int lmax = 2;
        int nt = 3;
        Map<Temporal<double>> map(lmax, nt);
        
        // Give the star a time-variable total flux
        Vector<double> y00(nt);
        y00 << 1.0, -0.5, 0.25;
        map.setY(0, 0, y00);

        // Set the linear and quadratic
        // limb darkening coefficients
        map.setU(1, 0.4);
        map.setU(2, 0.26);

        // Compute the flux and the derivatives at t = 0.5
        double t = 0.5;
        Vector<double> b(nb); 
        b = Vector<double>::LinSpaced(nb, -2.5, 2.5);
        Vector<double> flux(nb);
        Vector<double> dt(nb);
        Vector<double> dtheta(nb);
        Vector<double> dxo(nb);
        Vector<double> dyo(nb);
        Vector<double> dro(nb);
        Matrix<double> dy(nb, nt);
        Matrix<double> du(nb, lmax);
        for (int i = 0; i < nb; ++i)
            map.computeFlux(t, 0.0, b(i), 0.0, 0.1, flux.row(i), dt.row(i),
                            dtheta.row(i), dxo.row(i), dyo.row(i), 
                            dro.row(i), dy.row(i), 
                            du.row(i).transpose());

        // -- Now compute the derivatives numerically --

        // Instantiate the default map
        Map<Temporal<Multi>> map_multi(lmax, nt);
        
        // Give the star unit flux
        map_multi.setY(0, 0, y00.template cast<Multi>());

        // Set the linear and quadratic
        // limb darkening coefficients
        map_multi.setU(1, 0.4);
        map_multi.setU(2, 0.26);

        // Compute the derivatives
        Multi eps = 1.e-15;
        Vector<Multi> eps0(3), 
                      eps1(3), 
                      eps2(3);
        eps0 << eps, 0, 0;
        eps1 << 0, eps, 0;
        eps2 << 0, 0, eps;
        Vector<Multi> f1(1), f2(1);
        Vector<Multi> dt_multi(nb),
                    dtheta_multi(nb),
                    dxo_multi(nb),
                    dyo_multi(nb),
                    dro_multi(nb);
        Matrix<Multi> dy_multi(nb, nt);
        Matrix<Multi> du_multi(nb, lmax);
        for (int i = 0; i < nb; ++i) {
            map_multi.computeFlux(t - eps, 0.0, Multi(b(i)), 0.0, 0.1, f1);
            map_multi.computeFlux(t + eps, 0.0, Multi(b(i)), 0.0, 0.1, f2);
            dt_multi(i) = (f2(0) - f1(0)) / (2 * eps);
            
            map_multi.computeFlux(t, 0.0 - eps, Multi(b(i)), 0.0, 0.1, f1);
            map_multi.computeFlux(t, 0.0 + eps, Multi(b(i)), 0.0, 0.1, f2);
            dtheta_multi(i) = (f2(0) - f1(0)) / (2 * eps);

            map_multi.computeFlux(t, 0.0, Multi(b(i)) - eps, 0.0, 0.1, f1);
            map_multi.computeFlux(t, 0.0, Multi(b(i)) + eps, 0.0, 0.1, f2);
            dxo_multi(i) = (f2(0) - f1(0)) / (2 * eps);

            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0 - eps, 0.1, f1);
            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0 + eps, 0.1, f2);
            dyo_multi(i) = (f2(0) - f1(0)) / (2 * eps);

            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0, 0.1 - eps, f1);
            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0, 0.1 + eps, f2);
            dro_multi(i) = (f2(0) - f1(0)) / (2 * eps);

            map_multi.setY(0, 0, y00.template cast<Multi>() - eps0);
            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0, 0.1, f1);
            map_multi.setY(0, 0, y00.template cast<Multi>() + eps0);
            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0, 0.1, f2);
            map_multi.setY(0, 0, y00.template cast<Multi>());
            dy_multi(i, 0) = (f2(0) - f1(0)) / (2 * eps);

            map_multi.setY(0, 0, y00.template cast<Multi>() - eps1);
            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0, 0.1, f1);
            map_multi.setY(0, 0, y00.template cast<Multi>() + eps1);
            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0, 0.1, f2);
            map_multi.setY(0, 0, y00.template cast<Multi>());
            dy_multi(i, 1) = (f2(0) - f1(0)) / (2 * eps);

            map_multi.setY(0, 0, y00.template cast<Multi>() - eps2);
            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0, 0.1, f1);
            map_multi.setY(0, 0, y00.template cast<Multi>() + eps2);
            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0, 0.1, f2);
            map_multi.setY(0, 0, y00.template cast<Multi>());
            dy_multi(i, 2) = (f2(0) - f1(0)) / (2 * eps);

            map_multi.setU(1, 0.4 - eps);
            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0, 0.1, f1);
            map_multi.setU(1, 0.4 + eps);
            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0, 0.1, f2);
            map_multi.setU(1, 0.4);
            du_multi(i, 0) = (f2(0) - f1(0)) / (2 * eps);

            map_multi.setU(2, 0.26 - eps);
            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0, 0.1, f1);
            map_multi.setU(2, 0.26 + eps);
            map_multi.computeFlux(t, 0.0, Multi(b(i)), 0.0, 0.1, f2);
            map_multi.setU(2, 0.26);
            du_multi(i, 1) = (f2(0) - f1(0)) / (2 * eps);
        }

        // Compare
        int nerr = 0;
        if (!dt.isApprox(dt_multi.template cast<double>())) {
            std::cout << "Wrong t deriv in `test_flux_with_grad`." << std::endl;
            ++nerr;
        }
        if (!dtheta.isApprox(dtheta_multi.template cast<double>())) {
            std::cout << "Wrong theta deriv in `test_flux_with_grad`." << std::endl;
            ++nerr;
        }
        if (!dxo.isApprox(dxo_multi.template cast<double>())) {
            std::cout << "Wrong xo deriv in `test_flux_with_grad`." << std::endl;
            ++nerr;
        }
        if (!dyo.isApprox(dyo_multi.template cast<double>())) {
            std::cout << "Wrong yo deriv in `test_flux_with_grad`." << std::endl;
            ++nerr;
        }
        if (!dro.isApprox(dro_multi.template cast<double>())) {
            std::cout << "Wrong ro deriv in `test_flux_with_grad`." << std::endl;
            ++nerr;
        }
        if (!dy.isApprox(dy_multi.template cast<double>())) {
            std::cout << "Wrong y deriv in `test_flux_with_grad`." << std::endl;
            
            std::cout << dy << std::endl << std::endl;
            std::cout << dy_multi << std::endl;

            ++nerr;
        }
        if (!du.isApprox(du_multi.template cast<double>())) {
            std::cout << "Wrong u deriv in `test_flux_with_grad`." << std::endl;
            ++nerr;
        }
        return nerr;
    }

    int test () {
        return test_flux() + 
               test_flux_with_grad();
    }

} // namespace test_temporal
#endif