// Address: 0x14017daa0
// Ghidra name: FUN_14017daa0
// ============ 0x14017daa0 FUN_14017daa0 (size=102) ============


void FUN_14017daa0(undefined1 *param_1,int param_2,undefined4 param_3,int param_4,int param_5)



{

  undefined1 *puVar1;

  int iVar2;

  

  if (param_5 != 0) {

    do {

      param_5 = param_5 + -1;

      puVar1 = param_1;

      for (iVar2 = param_4; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar1 = (char)param_3;

        puVar1[1] = (char)((uint)param_3 >> 8);

        puVar1[2] = (char)((uint)param_3 >> 0x10);

        puVar1 = puVar1 + 3;

      }

      param_1 = param_1 + param_2;

    } while (param_5 != 0);

  }

  return;

}




