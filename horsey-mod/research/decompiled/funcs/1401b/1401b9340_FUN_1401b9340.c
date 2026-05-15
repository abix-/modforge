// Address: 0x1401b9340
// Ghidra name: FUN_1401b9340
// ============ 0x1401b9340 FUN_1401b9340 (size=73) ============


void FUN_1401b9340(longlong param_1,longlong param_2)



{

  if (param_2 != 0) {

    FUN_1401b9390();

    if (*(longlong *)(param_2 + 0x30) != 0) {

      (**(code **)(param_1 + 0xc98))

                (*(undefined8 *)(param_1 + 0x570),*(longlong *)(param_2 + 0x30),0);

      *(undefined8 *)(param_2 + 0x30) = 0;

    }

  }

  return;

}




