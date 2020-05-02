#ifndef _STARRY_REFLECTED_OREN_NAYAR_H_
#define _STARRY_REFLECTED_OREN_NAYAR_H_

#define STARRY_OREN_NAYAR_DEG 5
#define STARRY_OREN_NAYAR_N 36
#define STARRY_OREN_NAYAR_NB 4

static const double STARRY_OREN_NAYAR_COEFFS[] = {
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00, -4.703472841057599e+04,  4.048593492009733e+03,
 4.256215364095968e+04,  0.000000000000000e+00, -1.790155592366897e+04,
 8.540365352273504e+03,  5.703685988698328e+03,  0.000000000000000e+00,
 2.897671410631113e+04,  4.962069698011785e+03,  7.413327593574546e+02,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
-1.573855831435649e+05, -3.875387869822396e+03,  1.616847250756965e+05,
 0.000000000000000e+00,  1.771215945591373e+04, -8.234827043812629e+03,
-5.823776742366745e+03,  0.000000000000000e+00,  1.752542400131302e+05,
-4.829446748542864e+03, -7.875400546958826e+02,  0.000000000000000e+00,
 0.000000000000000e+00,  1.573855831435649e+05,  3.875387869822396e+03,
-1.616847250756965e+05,  4.340674683268942e+05, -9.635979374150178e+04,
-3.466588510913835e+05,  5.823776742366745e+03,  1.019449410529704e+05,
-3.188364410253526e+05,  5.156357967664374e+04,  7.875400546958826e+02,
-3.321224263040652e+05, -6.488165347387080e+04,  1.961128799920873e+04,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  6.403778601249590e+04,
 1.234948929018284e+04, -7.568406024832171e+04,  0.000000000000000e+00,
 1.129176237741541e+04,  2.029141822853227e+04, -2.539657744506662e+04,
 0.000000000000000e+00, -5.249010764844128e+04,  7.172489491261440e+03,
-7.683648468830574e+03,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  4.703472841057599e+04,
-4.048593492009733e+03, -4.256215364095968e+04, -1.527157203597609e+04,
 9.641127564943706e+04, -7.230497515666105e+04, -5.703685988698328e+03,
-1.017686922421859e+05,  1.143334804403638e+05, -5.159104234651359e+04,
-7.413327593574546e+02, -8.649722042431177e+04,  6.474752489659232e+04,
-1.955837631301334e+04,  0.000000000000000e+00,  0.000000000000000e+00,
 1.527157203597609e+04, -7.850971972576808e+04,  6.376460980438755e+04,
 4.443969649645811e+05,  1.373357193712670e+05, -6.228969499395456e+05,
 4.662897264850180e+04, -2.455432059310641e+04,  1.469976367394390e+05,
-9.746132152105284e+04,  1.955837631301334e+04, -4.686953448281789e+05,
 2.425277933322564e+04, -1.016512739986885e+04,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00, -3.550817492473000e+05,
-1.699017973128758e+04,  3.715803007121024e+05,  0.000000000000000e+00,
 3.006393197252173e+02, -2.923900661350661e+04,  2.458597842232420e+04,
 0.000000000000000e+00,  3.552049231274110e+05, -1.171625947221470e+04,
 8.119972381220547e+03,  0.000000000000000e+00,  0.000000000000000e+00,
 3.550817492473000e+05,  1.699017973128758e+04, -3.715803007121024e+05,
 7.815867817776173e+05,  1.017985104936801e+05, -8.551405961717162e+05,
-2.458597842232420e+04, -1.344782875716687e+05, -1.687571733934418e+05,
-4.722255249018229e+04, -8.119972381220547e+03, -9.160652192886875e+05,
 8.426648668615316e+04, -2.473593213563131e+04,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
-4.340674683268942e+05,  7.864763428558805e+04,  3.548936781351962e+05,
-6.063255705562630e+04, -1.417286908952405e+05,  2.438558183542434e+05,
-4.673413292810088e+04,  3.630384916560545e+04,  2.635657569511952e+05,
 9.588712202293282e+04, -1.961128799920873e+04,  9.675891534841679e+04,
-2.833217633098118e+04,  1.019864362991502e+04,  0.000000000000000e+00,
 0.000000000000000e+00,  6.063255705562630e+04,  3.978374984227006e+04,
-1.002736173420210e+05,  1.123412974618321e+06,  7.016682083988187e+04,
-1.161912771384663e+06, -3.100546854906201e+04, -1.348733603988684e+05,
 9.820094765249587e+04, -3.778419059786086e+04, -1.019864362991502e+04,
-1.258286469704737e+06,  8.840503417534847e+04, -2.786541764717186e+04,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00, -1.700305760191991e+04,
-1.639808278219257e+04,  3.312190660736203e+04,  0.000000000000000e+00,
 6.609793546253560e+03, -2.883178358080577e+04,  1.969289145636829e+04,
 0.000000000000000e+00,  2.351339354213015e+04, -1.213455918927322e+04,
 6.942315709473119e+03,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00, -1.700305760191991e+04,
-1.639808278219257e+04,  3.312190660736203e+04, -1.537791316041658e+06,
-5.661499303728508e+04,  1.572591843543664e+06,  1.969289145636829e+04,
 8.307433002225679e+04, -9.189685710587191e+04,  2.442809539837261e+04,
 6.942315709473119e+03,  1.620865738074587e+06, -5.213786166388752e+04,
 1.531529916350245e+04,  0.000000000000000e+00,  0.000000000000000e+00,
 1.537791316041658e+06,  6.322478658353864e+04, -1.601423627124470e+06,
-4.143652941559250e+05, -1.390880334255402e+05,  5.855567590072751e+05,
-3.656265458764584e+04,  4.906567006302894e+04, -1.718738303322794e+06,
 9.884086375601801e+04, -1.531529916350245e+04,  4.632320242639979e+05,
-4.134940822051065e+04,  1.636611034998452e+04,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
-3.973622365540051e+05, -3.961562062109083e+04,  4.370246017519110e+05,
 1.063528714010242e+05, -2.558792994031826e+04, -1.070955982644671e+05,
 2.701011063576219e+04,  8.343497056506113e+04,  3.149856023217129e+05,
 1.513687560884861e+04,  9.423794640511398e+03, -2.291781906136072e+04,
-5.664079048003478e+04,  1.864168657350255e+04,  0.000000000000000e+00,
 0.000000000000000e+00, -1.063528714010242e+05,  6.804380645709364e+04,
 3.805481659706635e+04, -3.973622365540051e+05, -1.230505911861520e+05,
 5.617576301520658e+05, -4.435172464008603e+04,  4.245587651677538e+04,
-4.612296260604006e+04,  8.365090111579698e+04, -1.864168657350255e+04,
 4.397186307218677e+05, -2.921484903123742e+04,  9.423794640511398e+03,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 1.502224608310995e+05,  1.529468781051725e+04, -1.654216791644800e+05,
 0.000000000000000e+00, -1.188852983683970e+04,  2.732127180171803e+04,
-1.456798444336681e+04,  0.000000000000000e+00, -1.620772446411636e+05,
 1.193422898187764e+04, -5.539244271734817e+03,  0.000000000000000e+00,
 0.000000000000000e+00, -1.502224608310995e+05, -1.529468781051725e+04,
 1.654216791644800e+05, -1.215654250104511e+06, -1.156298569097759e+04,
 1.211952009118701e+06,  1.456798444336681e+04,  3.253334651869830e+04,
 1.192116959194168e+05,  2.704500524184696e+02,  5.539244271734817e+03,
 1.248187645592753e+06, -1.938483321228237e+04,  5.124644136422581e+03,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00, -1.215654250104511e+06, -2.345151552781729e+04,
 1.239273280920419e+06,  3.040857826000069e+06,  7.698248130165084e+04,
-3.128129846628066e+06,  1.220467903429611e+04, -4.505047554241273e+04,
 1.326661561214224e+06, -5.266037489784704e+04,  5.124644136422581e+03,
-3.085840787063425e+06,  3.389622386241532e+04, -1.234948111922179e+04,
 0.000000000000000e+00,  0.000000000000000e+00, -3.040857826000069e+06,
-4.444913478295255e+04,  3.085264297906319e+06, -2.773134693049726e+06,
-6.224075705303825e+03,  2.746162484171677e+06,  3.327554168556468e+04,
 6.546176586459629e+04,  2.991597576352987e+06, -2.309310827378053e+03,
 1.234948111922179e+04,  2.838596541601554e+06, -4.290821391376003e+04,
 1.337877378438571e+04,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00,  0.000000000000000e+00,
 0.000000000000000e+00,  0.000000000000000e+00, -1.557480442945215e+06,
-2.782303571989927e+04,  1.585363118872729e+06, -5.588817984426753e+05,
 6.489598331951637e+04,  4.755280533281068e+05,  1.938223400074115e+04,
-3.468556215924692e+04,  1.646860672428097e+06, -4.566438494191455e+04,
 8.254129647963127e+03,  5.242299981076086e+05,  2.445230353027928e+04,
-8.267254742374997e+03,  0.000000000000000e+00,  0.000000000000000e+00,
 5.588817984426753e+05, -3.196756397361838e+04, -5.269057153167970e+05,
-1.557480442945215e+06,  6.862526439347650e+03,  1.528911342453434e+06,
 2.214100424043688e+04,  3.292841934589799e+04, -5.756076600962989e+05,
-5.070069529538127e+03,  8.267254742374997e+03,  1.590408896008802e+06,
-2.352338070147767e+04,  8.254129647963127e+03,  0.000000000000000e+00
};
#endif
