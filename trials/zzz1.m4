m4_define(`REQ_FUNCS',
  int foo()
  {
    return 8;
  }

  void hello_World()
  {
    printf("Hello world");
    return 0;
  }
')

m4_define(`HOP_BEST', unsigned int $1 = foo() ')
