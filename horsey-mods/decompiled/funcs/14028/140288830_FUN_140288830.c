// Address: 0x140288830
// Ghidra name: FUN_140288830
// ============ 0x140288830 FUN_140288830 (size=130) ============


void FUN_140288830(longlong param_1,int param_2)



{

  longlong lVar1;

  

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x30));

  *(undefined8 *)(param_1 + 0x30) = 0;

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x20));

  lVar1 = *(longlong *)(param_1 + 0x40);

  *(undefined8 *)(param_1 + 0x20) = 0;

  if (lVar1 != 0) {

    if (param_2 == 0x8000) {

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0x10));

      *(undefined8 *)(lVar1 + 0x10) = 0;

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x40));

    *(undefined8 *)(param_1 + 0x40) = 0;

  }

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x28));

  *(undefined8 *)(param_1 + 0x28) = 0;

  return;

}




