// Address: 0x1401b90a0
// Ghidra name: FUN_1401b90a0
// ============ 0x1401b90a0 FUN_1401b90a0 (size=100) ============


void FUN_1401b90a0(longlong param_1,longlong param_2)



{

  if (*(longlong *)(param_2 + 0x20) != 0) {

    (**(code **)(param_1 + 3000))(*(undefined8 *)(param_1 + 0x570),*(longlong *)(param_2 + 0x20),0);

  }

  if (*(longlong *)(param_2 + 0x18) != 0) {

    (**(code **)(param_1 + 0xbe8))(*(undefined8 *)(param_1 + 0x570),*(longlong *)(param_2 + 0x18),0)

    ;

  }

  FUN_1401841e0(param_2);

  return;

}




