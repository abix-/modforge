// Address: 0x140168fa0
// Ghidra name: FUN_140168fa0
// ============ 0x140168fa0 FUN_140168fa0 (size=100) ============


void FUN_140168fa0(int param_1)



{

  longlong lVar1;

  

  lVar1 = FUN_14016dcf0();

  if ((lVar1 != 0) && ((param_1 == 0 || (param_1 == *(int *)(lVar1 + 0x358))))) {

    if (*(code **)(lVar1 + 0x368) != (code *)0x0) {

      (**(code **)(lVar1 + 0x368))(*(undefined8 *)(lVar1 + 0x370));

    }

    FUN_140169150(lVar1);

    *(undefined8 *)(lVar1 + 0x360) = 0;

    *(undefined8 *)(lVar1 + 0x368) = 0;

    *(undefined8 *)(lVar1 + 0x370) = 0;

  }

  return;

}




