class Triangulo{
	costructor(base, altura){
		this.base = base;
		this.altura = altura;
	}

	get Area(){
		return this.calcularArea();
	}
	calcularArea(){
		return ((this.base * this.altura)/2);
	}
}

const TrianguloX = new Triangulo(15,25);
console.log(TrianguloX.Area);