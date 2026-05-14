// Address: 0x140087e30
// Ghidra name: FUN_140087e30
// ============ 0x140087e30 FUN_140087e30 (size=99) ============


void FUN_140087e30(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)



{

  undefined8 *puVar1;

  undefined8 uVar2;

  undefined8 *puVar3;

  longlong lVar4;

  

  if (param_1 != param_2) {

    lVar4 = (longlong)param_3 - (longlong)param_1;

    puVar3 = param_1 + 3;

    do {

      *param_3 = 0;

      param_3[1] = 0;

      *(undefined8 *)((longlong)puVar3 + lVar4 + -8) = 0;

      puVar1 = puVar3 + 1;

      *(undefined8 *)((longlong)puVar3 + lVar4) = 0;

      uVar2 = puVar3[-2];

      *param_3 = puVar3[-3];

      param_3[1] = uVar2;

      uVar2 = *puVar3;

      param_3[2] = puVar3[-1];

      param_3[3] = uVar2;

      puVar3[-1] = 0;

      param_3 = param_3 + 4;

      *puVar3 = 0xf;

      *(undefined1 *)(puVar3 + -3) = 0;

      puVar3 = puVar3 + 4;

    } while (puVar1 != param_2);

  }

  return;

}




