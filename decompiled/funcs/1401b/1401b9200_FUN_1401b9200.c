// Address: 0x1401b9200
// Ghidra name: FUN_1401b9200
// ============ 0x1401b9200 FUN_1401b9200 (size=55) ============


void FUN_1401b9200(longlong param_1,longlong param_2)



{

  if (param_2 != 0) {

    if (*(longlong *)(param_2 + 8) != 0) {

      (**(code **)(param_1 + 0xb88))(*(undefined8 *)(param_1 + 0x570),*(longlong *)(param_2 + 8),0);

    }

    FUN_1401841e0(param_2);

  }

  return;

}




