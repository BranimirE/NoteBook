    scanf("%llu %llu", &a, &b);
    if(a <= 1)a = 2;//Causa error con en 1 (No es primo)
    fill(p2, p2 + MAX, true);
    int ptr = 0;
    while(primos[ptr] * primos[ptr] <= b) {
      unsigned long long int ini = a;
      if(a % primos[ptr] != 0 ) ini += (primos[ptr] - (a % primos[ptr]));//el siguiente multiplo de primos[ptr]
      if(ini <= primos[ptr]) ini += primos[ptr];//Si es primo
      while(ini <= b) {
        p2[ini - a] = false;
        ini += primos[ptr];
      }
      ptr++;
    }
    unsigned long long int ans = 0, primos = 0;
    for(unsigned long long int i = a; i <= b; i++)
      if(p2[i - a])
        primos++;