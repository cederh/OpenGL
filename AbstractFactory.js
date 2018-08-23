/*
    INGENIERÍA DE SOFTWARE.
    PATRÓN DE DISEÑO ABSTRACT FACTORY.
    DOCENTE: ING. MILAGRO ALICIA DE REYES.
    POR: BACH. RAÚL MAURICIO PORTILLO.
    "UTILIZANDO ES5 - (ECMA SCRIPT 5)".
    
    Información: En el caso de trabajar con JavaScript(JS), no podremos utilizar Interface u Implements, ya que como tal,
    JS no lo soporta, y en el caso de este patrón en específico, no será necesario recrear ciertas Abstracciones ya que
    estas son implementaciones vacías.
    Interectuadores:
        Los objetos que participan en este patrón son: 
            #AbstractFactory : No se utilizara en JavaScript, ya que este declara una interfaz
            para crear productos que es vacía, para crear dichos productos(En nuestro caso estudiantes),
            utilizaremos instancias.
            #ConcreteFactory - EstudianteUESFactory, DocenteUESFactory; un objeto de fábrica que 'fabrica' nuevos
            productos el método create () devuelve nuevos productos.
            #Productos - En código de muestra: EstudiantesUES, DocenteUES las instancias del producto están siendo
            creadas(agregadas) por la fábrica.
            #AbstractProduct - No se usa en JavaScript, declara una interfaz para los productos que se están creando.
    NOTA: "SI DESEAMOS APLICAR EL METODO (ABSTRACT FACTORY CON IMPLEMENTS Y ABSTRACT (POO), SERA NESESARIO TRABAJAR
           BAJO LA EXTENSIÓN .TS(TypeScript - Este es un transpilador de código de JS que nos permite ejecutar de una
           mejor manera el paradigma de POO), Y ASÍ PODER IMPLEMENTAR EL PATRÓN EN BASE ES6".
*/

class EstudianteUES {                           // CREAMOS CLASE DONDE AGREGAMOS UN ESTUDIANTE.
    constructor(nombre) {                       // EL CONTRUCTOR RECIBE EL PARAMETRO DE (NOMBRE).
        this.nombre = nombre;                   // DECIMOS QUE ESTA VAR: NOMBRE ES IGUAL A NOMBRE
        this.say = function () {                // DECIMOS QUE ESTA FUNCION AGREGA UN NUEVO ESTUDIANTE.
            alertaAF.add("Estudiante:  " + nombre);  // CONCATENAMOS EL VALOR U STRING Y LO AGREGAMOS.
        };
    }
}
 
class EstudianteUESFactory {                    // CREAMOS CLASE.
    constructor() {
        this.create = function (nombre) {       // FUNCIÓN QUE CREA UN NUEVO ESTUDIANTE (RECIBE EL PARAMETRO DE NOMBRE).
            return new EstudianteUES(nombre);   // NOS RETORNA UN NUEVO OBJETO(ESTUDIANTE).
        };
    }
}
 
class DocenteUES {                              // CREAMOS CLASE DONDE AGREGAMOS UN DOCENTE.
    constructor(nombre) {                       // EL CONTRUCTOR RECIBE EL PARAMETRO DE (NOMBRE).
        this.nombre = nombre;                   // DECIMOS QUE ESTA VAR: NOMBRE ES IGUAL A NOMBRE
        this.say = function () {                // DECIMOS QUE ESTA FUNCION AGREGA UN NUEVO DOCENTE.
            alertaAF.add("Docente:  " + nombre);     // CONCATENAMOS EL VALOR U STRING Y LO AGREGAMOS.
        };
    }
}
 
class DocenteUESFactory {                       // CREAMOS CLASE.
    constructor() {
        this.create = function (nombre) {       // FUNCIÓN QUE CREA UN NUEVO DOCENTE (ESTE RECIBE EL PARAMETRO DE NOMBRE TAMBIÉN).
            return new DocenteUES(nombre);      // NOS RETORNA UN NUEVO OBJETO(DOCENTE).
        };
    }
}
 
// MOSTRAR ALERTA U MENSAJE - MAQUETADO WEB
var alertaAF = (function () {
    var alertaAF = "";
 
    return {
        add: function (msg) {
             alertaAF += msg + "\n"; // POR CADA personaUES AGREGADA, SE INSERTA UN SALTO DE LINEA.
        },
        show: function () { // PASAMOS LOS DATOS A LA FUNCIÓN PARA SER IMPRESOS EN LA ALERTA.
            alert(alertaAF); // MOSTRAMOS EN UN SWEETALERT SENCILLO - LOS ESTUDIANTES & DOCENTES.
            alertaAF = ""; 
        }
    }
})();

// FUNCIÓN ENCARGADA DE EJECUTAR EL PATRÓN ABSTRACT FACTORY.
function ejecutarAF() {
    // DECLARAMOS VARIABLES
    var personasUES =  new Array();                     // CREAMOS VECTOR DONDE ALMACENAREMOS LOS DATOS DE ESTUDIANTES Y DOCENTES.
    var estudianteFactory = new EstudianteUESFactory(); // CREAMOS NUEVO OBJETO ESTUDIANTEFACTORY.
    var docenteFactory = new DocenteUESFactory();       // CREAMOS NUEVO OBJETO DOCENTEFACTORY.
 
    // DENTRO DEL VECTOR, INSERTAMOS LOS ESTUDIANTES Y DOCENTES(FACTORY).
    personasUES.push(estudianteFactory.create("Laura Romero")); // "PUSH", ES UN MÉTODO DE JS, PARA AGREGARA NUEVOS INTEMS A UN ARRAY.
    personasUES.push(estudianteFactory.create("Dennis Samayoa"));
    personasUES.push(docenteFactory.create("Ing. Milagro de Reyes"));
    personasUES.push(docenteFactory.create("Ing. Astrid Bonilla"));
 
    // RECORREMOS EL VECTOR QUE ALMACENA A LOS ESTUDIANTES Y DOCENTES.
    for (var i = 0, len = personasUES.length; i < len; i++) {
        personasUES[i].say();
    }
 
    alertaAF.show(); // MUESTRA LOS ELEMENTOS OCULTOS Y SELECCIONADOS. 
}