#include <iostream>
#include <vector>

using namespace std;


int main() {
  int n, i, j, dimY;

  cout << "Di quanti elementi è composto il vettore?" << endl;
  cin >> n;
  vector<int> X(n);

  for (i = 0; i <= n - 1; i++) {
    cout << "Inserire il valore del " << i + 1 << "° elemento" << endl;
    cin >> X[i];
  }

  // Creo un nuovo vettore Y che conterrà tutti gli elementi distinti di X. Lo
  // dichiaro di dimensione N, ma la sua dimensione effettiva la calcolo man
  // mano che inserirò gli elementi in Y. Uso la variabile dimY per calcolare la
  // dimensione effettiva di Y.
  vector<int> Y(n);

  dimY = 0;

  // Per ottenere Y da X, dovrò rimuovere i duplicati da X.
  bool trovato;

  for (i = 0; i <= n - 1; i++) {

    // Per ogni elemento x di X,
    // Cerco l'elemento x in tutto Y (che sto man mano costruendo), quindi
    // scorro Y usando j da 0 a dimY-1. Inoltre se trovato=true (ho trovato x in
    // Y), esco dal ciclo abortendo la ricerca.
    trovato = false;
    j = 0;
    while (j <= dimY - 1 && !trovato) {
      if (X[i] == Y[j]) {

        // se x esiste già in Y, imposto una variabile trovato=true, in modo da
        // abortire subito la ricerca di x in Y e passare al prossimo elemento
        // di X
        trovato = true;
      }
      j = j + 1;
    }
    if (!trovato) {

      // se x non è stato trovato in Y, allora inserisco x in coda al vettore Y
      Y[dimY] = X[i];

      // ogni volta che inserisco un elemento in coda a Y, incremento la
      // dimensione di Y (dimY).
      dimY = dimY + 1;
    }
  }

  // Ordinamento del vettore Y
  int t;

  for (i = 0; i <= dimY - 1; i++) {
    for (j = 0; j <= dimY - i - 2; j++) {
      if (Y[j] > Y[j+1]) {
        t = Y[j];
        Y[j] = Y[j+1];
        Y[j+1] = t;
      }
    }
  }
  cout << "Vettore Y, ordinato e con i " << dimY << " elementi distinti di X:" << endl;
  for (i = 0; i <= dimY - 1; i++) {
    cout << Y[i] << endl;
  }
}

