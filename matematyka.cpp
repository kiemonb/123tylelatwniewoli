int add(int number_one, int number_two)
{
    return number_one + number_two;
}

bool czyZachwycajaca(int n) {
  int* dzielniki = new int[n / 2];
  int suma = 0, ile = 0;
  for (int i = 1; i <= n / 2; i++) {
    if (n % i == 0) {
      suma += i;
      dzielniki[ile++] = i;
    }
  }
  for (int i = 0; i < ile; i++) {
    if (n == suma - 2 * dzielniki[i]) {
      delete dzielniki;
      return true;
    }
  }
  delete dzielniki;
  return false;
}
int* generujCiag(int n) {
  int* tab = new int[n];
  tab[0] = 0;
  int limit = 1;
  int k = 0;
  for (int i = 1; i < n; i++) {
    if (i == limit) {
      limit *= 2;
      k = 0;
    }
    tab[i] = (tab[k++] + 1) % 2;
  }
  return tab;
}
bool czyNieliczna(int a) {
  bool ostatni = false;
  int p = 1;
  for (int i = 0; i <= sizeof(a) * 8; i++, p *= 2) {
    bool aktualny = a & p;
    if (ostatni && aktualny)
      return false;
    ostatni = aktualny;
  }
  return true;
}
