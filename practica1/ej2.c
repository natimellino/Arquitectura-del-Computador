int isOne(long int n, int b){
  return (n >> b) & 1;
}