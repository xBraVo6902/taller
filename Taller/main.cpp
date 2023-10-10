#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Incluye los archivos de cabecera de las clases necesarias
#include <Usuario.hpp>
#include <Administrador.hpp>
#include <Normal.hpp>
#include <Nino.hpp>

#include <Software.hpp>
#include <Juegos.hpp>
#include <Ofimatica.hpp>
#include <Produccion.hpp>
#include <Navegador.hpp>
#include <Seguridad.hpp>
#include <Social.hpp>

#include <Sistema.hpp>


using namespace std;



// Función que elimina un software de la biblioteca de un usuario
void eliminarSoftware(Sistema& sistema, const string& nombreUsuario){
    string nombreSoftware;
    cout << "Ingrese el nombre del software que desea eliminar: ";
    cin >> nombreSoftware;
    bool exito = sistema.eliminarSoftware(nombreUsuario, nombreSoftware);
    if (exito) {
        cout << "El software se eliminó con éxito." << endl;
    } else {
        cout << "No se pudo eliminar el software." << endl;
    }
    
}

// Función que muestra el registro de actividad del sistema
void mostrarRegistro(Sistema& sistema, const string& nombreUsuario){
    if (dynamic_cast<Administrador*>(sistema.getUsuario(nombreUsuario)) != nullptr) {
        sistema.getUsuario(nombreUsuario)->mostrarRegistroActividad(sistema.getRegistroActividad());
    } else {
        cout << "Acceso denegado. Solo los administradores pueden ver el registro de actividad." << endl;
    }
}

// Función que agrega un software a la biblioteca de un usuario
void agregarSoftware( Sistema& sistema, const string& nombreUsuario){
    string nombreSoftware;
    cout << "Ingrese el nombre del software que desea agregar: ";
    cin >> nombreSoftware;
    bool exito = sistema.agregarSoftware(nombreUsuario, nombreSoftware);
    if (exito) {
        cout << "El software se agregó con éxito." << endl;
    } else {
        cout << "No se pudo agregar el software." << endl;
    }
}

// Función que muestra el menú de un software de redes sociales
void softwareSocial( Sistema& sistema, const string& nombreUsuario, int opcion, Social* social){
    cout << "Usando el software social: " << social->getNombre() << endl;
    cout << "Menú:" << endl;
    cout << "1. Agregar amigo" << endl;
    cout << "2. Eliminar amigo" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    if (opcion == 1) {
        string nombreAmigo;
        cout << "Ingrese el nombre del amigo que desea agregar: ";
        cin >> nombreAmigo;
        social->agregarUsuarioSocial(nombreAmigo);
        cout << "Amigo agregado con éxito." << endl;
    } else if (opcion == 2) {
        string nombreAmigo;
        cout << "Ingrese el nombre del amigo que desea eliminar: ";
        cin >> nombreAmigo;
        social->eliminarUsuarioSocial(nombreAmigo);
        cout << "Amigo eliminado con éxito." << endl;
    } else {
        cout << "Opción no válida." << endl;
    }
}

// Función que muestra el menú de un software de seguridad
void softwareSeguridad( Sistema& sistema, const string& nombreUsuario, int opcion, Seguridad* seguridad){
    
    if (dynamic_cast<Administrador*>(sistema.getUsuario(nombreUsuario)) != nullptr) {
        cout << "Usando el software de seguridad: " << seguridad->getNombre() << endl;
        cout << "Menú:" << endl;
        cout << "1. Escanear" << endl;
        cout << "2. Ver tipo de malware" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        
        if (opcion == 1) {
            cout << "Escaneando..." << endl;
        } else if (opcion == 2) {
            cout << "Tipo de malware: " << seguridad->getTipoMalware() << endl;
        } else {
            cout << "Opción no válida." << endl;
        }
    } else {
        cout << "Acceso denegado. Solo los administradores pueden usar el software de seguridad." << endl;
    }
}

// Función que muestra el menú de un software de navegación
void softwareNavegacion( Sistema& sistema, const string& nombreUsuario, int opcion, Navegador* navegador){
    cout << "Usando el navegador: " << navegador->getNombre() << endl;
    cout << "Menú:" << endl;
    cout << "1. Hacer una busqueda" << endl;
    cout << "2. Ver historial de navegación" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    if (opcion == 1) {
        string busqueda;
        cout << "Ingrese la busqueda que desea hacer: ";
        cin >> busqueda;
        cout << "Buscando " << busqueda << "..." << endl;
        navegador->agregarPaginaAlHistorial(busqueda);
    } else if (opcion == 2) {
        cout << "Historial de navegación:" << endl;
        for (const string& pagina : navegador->getHistorialNavegacion()) {
            cout << pagina << endl;
        }
    } else {
        cout << "Opción no válida." << endl;
    }
}

// Función que muestra el menú de un software de producción
void softwareProduccion( Sistema& sistema, const string& nombreUsuario, int opcion, Produccion* prod){
    cout << "Usando el software de producción: " << prod->getNombre() << endl;
    cout << "Menú:" << endl;
    cout << "1. Crear solución" << endl;
    cout << "2. Eliminar solución" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    if (opcion == 1) {
        cout << "Creando solución..." << endl;
    } else if (opcion == 2) {
        cout << "Eliminando solución..." << endl;
    } else {
        cout << "Opción no válida." << endl;
    }
}

// Función que muestra el menú de un software de ofimática
void softwareOfimatica( Sistema& sistema, const string& nombreUsuario, int opcion, Ofimatica* ofi){
    cout << "Usando el software de ofimática: " << ofi->getNombre() << endl;
    cout << "Menú:" << endl;
    cout << "1. Crear archivo" << endl;
    cout << "2. Eliminar archivo" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    if (opcion == 1) {
        ofi->crearArchivo();
        cout << "Archivo creado con éxito." << endl;
    } else if (opcion == 2) {
        ofi->borrarArchivo();
        cout << "Archivo eliminado con éxito." << endl;
    } else {
        cout << "Opción no válida." << endl;
    }
}

// Función que muestra el menú de un software de juegos
void softwareJuego( Sistema& sistema, const string& nombreUsuario, int opcion, Juegos* juego){
    cout << "Usando el juego: " << juego->getNombre() << endl;
    cout << "Menú:" << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Ver géneros" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    if (opcion == 1) {
        cout << "Jugando..." << endl;
    } else if (opcion == 2) {
        cout << "Géneros:" << endl;
        for (const string& genero : juego->getGeneros()) {
            cout << genero << endl;
        }
    } else {
        cout << "Opción no válida." << endl;
    }
}

// Función que muestra la biblioteca de un usuario y le permite elegir un software para usar
void mostrarBiblioteca(Sistema& sistema, const string& nombreUsuario, int opcion){
    sistema.getUsuario(nombreUsuario)->verBiblioteca();
    if (sistema.getUsuario(nombreUsuario)->getBiblioteca().empty()) {
        cout << "Biblioteca vacía." << endl;
    }
    
    cout << "Ingrese el nombre del software que desea utilizar: ";
    string nombreSoftware;
    cin.ignore(); 
    getline(cin, nombreSoftware);

    // Busca el software en la base de datos
    Software* softwareElegido = sistema.getSoftware(nombreSoftware);

    if (softwareElegido) {
        const vector<string>& usuariosConAcceso = softwareElegido->getUsuarios();
        bool tieneAcceso = false;
        for (const string& usuario : usuariosConAcceso) {
            if (usuario == nombreUsuario) {
                tieneAcceso = true;
                break;
            }
        }
        // Si el usuario tiene acceso al software, se ejecuta el menú correspondiente
        if (tieneAcceso) {
            if (Juegos* juego = dynamic_cast<Juegos*>(softwareElegido)) {
                softwareJuego(sistema, nombreUsuario, opcion, juego); // Llama a la función que muestra el menú de un juego
            } else if (Ofimatica* ofi = dynamic_cast<Ofimatica*>(softwareElegido)) {
                softwareOfimatica(sistema, nombreUsuario, opcion, ofi); // Llama a la función que muestra el menú de un software de ofimática
            } else if (Produccion* prod = dynamic_cast<Produccion*>(softwareElegido)) {
                softwareProduccion(sistema, nombreUsuario, opcion, prod); // Llama a la función que muestra el menú de un software de producción
            } else if (Navegador* navegador = dynamic_cast<Navegador*>(softwareElegido)) {
                softwareNavegacion(sistema, nombreUsuario, opcion, navegador); // Llama a la función que muestra el menú de un software de navegación
            } else if (Seguridad* seguridad = dynamic_cast<Seguridad*>(softwareElegido)) {
                softwareSeguridad(sistema, nombreUsuario, opcion, seguridad); // Llama a la función que muestra el menú de un software de seguridad
            } else if (Social* social = dynamic_cast<Social*>(softwareElegido)) {
                softwareSocial(sistema, nombreUsuario, opcion, social); // Llama a la función que muestra el menú de un software de redes sociales
            } else {
                cout << "Este software no tiene una función específica definida." << endl;
            }
        } else {
            cout << "No tienes acceso a este software." << endl;
        }
    } else {
        cout << "El software no existe en la base de datos." << endl;
    }
}
// Función que ejecuta el sistema
void ejecutarSistema(Sistema& sistema){

    string nombreUsuario, contrasena;
    cout << "Ingrese su nombre de usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese la contraseña: ";
    cin >> contrasena;
    
    bool inicioSesionCorrecto = sistema.iniciarSesion(nombreUsuario, contrasena);

    // Si el inicio de sesión es correcto, se ejecuta el menú principal
    if (inicioSesionCorrecto) {
        cout << "Acceso correcto" << endl;
        int opcion;
    
        do {
            cout << "Menú:" << endl;
            cout << "1. Ver biblioteca" << endl;
            cout << "2. Agregar software" << endl;
            cout << "3. Eliminar software" << endl;
            cout << "4. Ver registro de actividad" << endl;
            cout << "5. Logout" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion;
    
            switch (opcion) {
                case 1: {
                    mostrarBiblioteca(sistema, nombreUsuario, opcion); // Llama a la función que muestra la biblioteca
                    break;
                }

                case 2: {
                    agregarSoftware(sistema, nombreUsuario); // Llama a la función que agrega un software
                    break;
                }
                case 3: {
                    eliminarSoftware(sistema, nombreUsuario); // Llama a la función que elimina un software
                    break;
                }
                case 4: {
                    mostrarRegistro(sistema, nombreUsuario); // Llama a la función que muestra el registro de actividad
                break;
                }
                // Si el usuario elige la opción 5, se le da la opción de cerrar sesión o terminar el programa
                case 5: {
                    int logoutOption;
                    cout << "1. Logear con otro usuario" << endl;
                    cout << "2. Terminar el programa" << endl;
                    cout << "Ingrese una opción: ";
                    cin >> logoutOption;
                    if (logoutOption == 1) {
                        ejecutarSistema(sistema);
                    } else if (logoutOption == 2) {
                        cout << "Saliendo del programa..." << endl;
                        
                    } else {
                        cout << "Opción no válida. Volviendo al menú principal." << endl;
                    }
                    break;
                }
                default: {
                    cout << "Opción no válida. Intente de nuevo." << endl;
                    break;
                }
            }
    
        } while (opcion != 5);
    } else {
        cout << "Acceso incorrecto" << endl;
    }
}

// Función principal
int main() {
    // Crear una instancia de la clase Sistema para administrar usuarios y software
    Sistema sistema; 
    // Crear instancias de usuarios y software
    Usuario* admin = new Administrador("admin", "admin", 21, "admin@example.com");
    Usuario* n1 = new Nino("Juanito", "1234", 12);
    Usuario* n2 = new Nino("Ana", "5678", 10);
    Usuario* n3 = new Nino("Pedro", "abcd", 8);
    Usuario* n4 = new Nino("Lucas", "efgh", 9);
    Usuario* u1 = new Normal("Marco", "ijkl", 18, "marco@example.com");
    Usuario* u2 = new Normal("Laura", "mnop", 20, "laura@example.com");
    Usuario* u3 = new Normal("Carla", "qrst", 25, "carla@example.com");
    Usuario* u4 = new Normal("Eduardo", "uvwx", 30, "eduardo@example.com");
    Usuario* u5 = new Normal("Isabel", "yzab", 22, "isabel@example.com");
    Usuario* u6 = new Normal("Carlos", "12345", 28, "carlos@example.com");
    Usuario* u7 = new Normal("AnaMaria", "abcdef", 24, "anamaria@example.com");
    Usuario* u8 = new Normal("Javier", "qwerty", 22, "javier@example.com");
    Usuario* u9 = new Normal("Mariana", "abc123", 30, "mariana@example.com");
    Usuario* u10 = new Normal("Lucia", "456789", 26, "lucia@example.com");

    // Agregar usuarios al sistema
    sistema.agregarUsuario(admin);
    sistema.agregarUsuario(n1);
    sistema.agregarUsuario(n2);
    sistema.agregarUsuario(n3);
    sistema.agregarUsuario(n4);
    sistema.agregarUsuario(u1);
    sistema.agregarUsuario(u2);
    sistema.agregarUsuario(u3);
    sistema.agregarUsuario(u4);
    sistema.agregarUsuario(u5);

    // Crear instancias de software (juegos, ofimática, producción, navegadores, seguridad, redes sociales)
    // Crea las instancias de software de juegos
    Software* j1 = new Juegos("God of War", "SCE Santa Monica Studio", 18, 40000);
    Software* j2 = new Juegos("Just Dance", "Ubisoft", 7, 2000);
    Software* j3 = new Juegos("Call of Duty", "Activision", 18, 50000);
    Software* j4 = new Juegos("Super Mario Bros", "Nintendo", 0, 3000);
    Software* j5 = new Juegos("Minecraft", "Mojang", 0, 2500);
    Software* j6 = new Juegos("FIFA 22", "EA Sports", 7, 4500);
    Software* j7 = new Juegos("Outlast", "Red Barrels", 18, 1000);
    Software* j8 = new Juegos("The Sims 4", "Electronic Arts", 12, 3500);
    Software* j9 = new Juegos("Civilization VI", "Firaxis Games", 12, 6000);
    Software* j10 = new Juegos("NBA 2K20", "EA Sports", 0, 4500);
    Software* j11 = new Juegos("Plantas vs Zombies", "PopCap Games", 0, 3500);
    Software* j12 = new Juegos("Red Dead Redemption 2", "Rockstar Games", 18, 4000);
    Software* j13 = new Juegos("Cyberpunk 2077", "CD Projekt", 18, 4500);
    Software* j14 = new Juegos("Battlefied 1", "Electronic Arts", 18, 3000);
    Software* j15 = new Juegos("The Crew 2", "Ubisoft", 10, 4500);
    Software* j16 = new Juegos("GTA V", "Rockstar Games", 18, 3500);
    Software* j17 = new Juegos("Terraria", "Re-Logic", 0, 3000);
    Software* j18 = new Juegos("Resident Evil 4", "Capcom", 16, 2500);
    Software* j19 = new Juegos("Mortal Kombat 11", "NetherRealm Studios", 18, 4000);
    Software* j20 = new Juegos("Forza Horizon 5", "XBOX Studio", 10, 4500);

    // Agregar géneros a los juegos
    static_cast<Juegos*>(j1)->agregarGenero("Pelea");
    static_cast<Juegos*>(j2)->agregarGenero("Simulación");
    static_cast<Juegos*>(j3)->agregarGenero("FPS");
    static_cast<Juegos*>(j4)->agregarGenero("Aventura");
    static_cast<Juegos*>(j5)->agregarGenero("Sandbox");
    static_cast<Juegos*>(j6)->agregarGenero("Deportes");
    static_cast<Juegos*>(j7)->agregarGenero("Terror");
    static_cast<Juegos*>(j8)->agregarGenero("Simulación");
    static_cast<Juegos*>(j9)->agregarGenero("Estrategia");
    static_cast<Juegos*>(j10)->agregarGenero("Deporte");
    static_cast<Juegos*>(j11)->agregarGenero("Estretegia");
    static_cast<Juegos*>(j12)->agregarGenero("Aventura");
    static_cast<Juegos*>(j13)->agregarGenero("RPG");
    static_cast<Juegos*>(j14)->agregarGenero("FPS");
    static_cast<Juegos*>(j15)->agregarGenero("Carrera");
    static_cast<Juegos*>(j16)->agregarGenero("RPG");
    static_cast<Juegos*>(j17)->agregarGenero("SandBox");
    static_cast<Juegos*>(j18)->agregarGenero("Terror");
    static_cast<Juegos*>(j19)->agregarGenero("Pelea");
    static_cast<Juegos*>(j20)->agregarGenero("Carrera");
    

    // Agregar los juegos al sistema
    sistema.agregarSoftware(j1);
    sistema.agregarSoftware(j2);
    sistema.agregarSoftware(j3);
    sistema.agregarSoftware(j4);
    sistema.agregarSoftware(j5);
    sistema.agregarSoftware(j6);
    sistema.agregarSoftware(j7);
    sistema.agregarSoftware(j8);
    sistema.agregarSoftware(j9);
    sistema.agregarSoftware(j10);

    // Crear instancias de software de ofimática
    Software* o1 = new Ofimatica("Microsoft Office", "Microsoft", 18, 20000);
    Software* o2 = new Ofimatica("LibreOffice", "The Document Foundation", 0, 0);
    Software* o3 = new Ofimatica("Google Docs", "Google", 0, 0);
    Software* o4 = new Ofimatica("WPS Office", "Kingsoft Office Software", 0, 0);
    Software* o5 = new Ofimatica("OnlyOffice", "Ascensio System SIA", 0, 0);

    // Agregar software de ofimatica al sistema
    sistema.agregarSoftware(o1);
    sistema.agregarSoftware(o2);
    sistema.agregarSoftware(o3);
    sistema.agregarSoftware(o4);
    sistema.agregarSoftware(o5);

    // Crear instancias de software de producción
    Software* p1 = new Produccion("AutoCAD", "Autodesk", 18, 5000, "Diseño 2D y 3D");
    Software* p2 = new Produccion("Adobe Premiere Pro", "Adobe", 18, 2500, "Edición de Video");
    Software* p3 = new Produccion("ProTools", "Avid", 18, 3000, "Producción de Audio");
    Software* p4 = new Produccion("SolidWorks", "Dassault Systèmes", 18, 4500, "Diseño de Ingeniería");

    // Agregar software de producción al sistema
    sistema.agregarSoftware(p1);
    sistema.agregarSoftware(p2);
    sistema.agregarSoftware(p3);
    sistema.agregarSoftware(p4);

    // Crear instancias de software de navegación
    Software* n5 = new Navegador("Google Chrome", "Google", 0, 0);
    Software* n6 = new Navegador("Mozilla Firefox", "Mozilla", 0, 0);

    // Agregar software de navegación al sistema
    sistema.agregarSoftware(n5);
    sistema.agregarSoftware(n6);

    // Crear instancias de software de seguridad
    Software* s3 = new Seguridad("Firewall Plus", "Tech Security", 0, 500, "Firewall");
    Software* s4 = new Seguridad("VirusShield", "ProtectSoft", 0, 300, "Antivirus");
    Software* s5 = new Seguridad("MalwareGuard", "CyberGuardians", 18, 1000, "Anti-Malware");
    Software* s6 = new Seguridad("PrivacyDefender", "Guardian Software", 0, 700, "Anti-Spyware");

    // Agregar software de seguridad al sistema
    sistema.agregarSoftware(s3);
    sistema.agregarSoftware(s4);
    sistema.agregarSoftware(s5);
    sistema.agregarSoftware(s6);

    // Crear instancias de software de redes sociales
    Software* s8 = new Social("Facebook", "Facebook", 18, 0);
    Software* s7 = new Social("Instagram", "Facebook", 13, 0);

    // Agregar software de redes sociales al sistema
    sistema.agregarSoftware(s8);
    sistema.agregarSoftware(s7);

    //Llammada a la funcion que ejecuta el sistema
    ejecutarSistema(sistema); 

    return 0;
} 
