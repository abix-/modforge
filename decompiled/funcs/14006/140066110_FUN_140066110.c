// Address: 0x140066110
// Ghidra name: FUN_140066110
// ============ 0x140066110 FUN_140066110 (size=110) ============


longlong FUN_140066110(longlong param_1,ulonglong param_2)



{

  FUN_140027900(param_1 + 0x300);

  FUN_140027900(param_1 + 0x2d8);

  _eh_vector_destructor_iterator_((void *)(param_1 + 600),0x20,4,FUN_140027900);

  FUN_1400c97f0(param_1);

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,0x328);

  }

  return param_1;

}




