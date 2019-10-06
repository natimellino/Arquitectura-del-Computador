unsigned mult(unsigned a, unsigned b) {
  if (b == 0) { // Si b es 0, retornamos 0.
    return 0;
  } else if (b == 1) { // Si b es 1, retornamos a.
    return a;
  } else if(!(isOne(b, 0))) { // Si el primer bit es 0, b es par.
    return mult(a << 1, b >> 1);
  } else { // b es impar.
    return a + mult(a << 1, b >> 1);
  }