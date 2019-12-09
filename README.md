# webcam_point_features
Detection of ORB features from online webcam imges.

Repositori original: https://github.com/beta-robots/webcam_point_features

ORB (Oriented FAST and Rotated BRIEF) és un algoritme de detecció de punts utilitzat, per exemple, en visió artificial pel reconeixement d'objectes o per la reconstrucció 3D. Aquest mètode es basa en la fusió de dos algoritmes.
D'una banda combina FAST Keypoint detector, i d'altra banda BRIEF descriptor.FAST s'utilitza per buscar els punts d’interès (keypoints), concretament es tracta d'un detector de cantonades que utilitza un cercle de 16 píxels per determinar si els candidats són o no són cantonades. FAST no computa la orientació i BRIEF, que incorpora els "descriptors", també realitza una computació pobre de l'orientació. ORB afegeix el càlcul dels moments per millorar l'estabilitat de la rotació.

En resum podriem dir que l'algoritme troba els keypoints utilitzant una versió modificada de FAST i els utilitza amb una versió, també modificada, del descriptor BRIEF per tal d’emmagatzemar la característica que li correspon a cada keypoint.
ORB apareix al 2011 de la ma de Etahn Rublee com alternativa a SURF i SIFT. Ofereix un rendiment superior, doncs funciona més ràpid que SURF i SIFT i el seu descriptor treballar millor que el de SURF. Cal mencionar a més que SIFT i SURF estan patentats i per tant es necessari pagar la llicencia per poder-ne fer usa, a diferencia de ORB que al ser de OpenCV es totalment gratuït.

Mask és un paràmetre opcional que indica on buscar keypoints a l'element a analitzar. Ha de ser una matriu (8-bits) de números enters, amb elements no nuls a la zona d’interès. Podríem dir, per tant, que aquest paràmetre ens permet triar la zona de la imatge on volem buscar els punts de interès o keypoints.

En aquest cas concret fem servir el paràmetre "factor" per controlar en quin % de la imatge es busquen keypoints. Aquest paràmetre es demana que sigui introduït per l'usuari i ha d'estar compres entre 0.0 i 1.0
Al repositori es troben algunes imatges d'exemple amb diferents valors pel paràmetre "factor" (0.0, 0.5, 1.0). Com més proper a 1.0 sigui el paràmetre podem veure com troba més punts d’interès.

Referencies:
https://medium.com/@deepanshut041/introduction-to-orb-oriented-fast-and-rotated-brief-4220e8ec40cf
https://opencv-python-tutroals.readthedocs.io/en/latest/py_tutorials/py_feature2d/py_orb/py_orb.html

Intruccions:
1. Fork del repositori al nostre espai de GitHub
2. Clone del repositori. Dins trobem l'arxiu CMakelists.txt, on es defineixen els paràmetres necesaaris per poder compilar, llibreries associades, nom de l'executable que es generarà, etc.
3. Dins del repo, afegim el directori "build" (mkdir build) i a l'interior executem "cmake .." (els ".." son per indicar que l'arxiu de config "CMakelists.txt" es troba al directori superior)
4. Seguidament dins de /build executem "make" per que es el compili el script en .cpp que es troba al directori /src. Obtenim un executable
5. Ja podem fer anar l'executable (./exe). Per fer anar l'executable cal estar dins del direcori on es troba. Si es fa al algún canvi al script cal tornar a repetir el proces per generar un nou executable.


