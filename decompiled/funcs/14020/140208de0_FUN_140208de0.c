// Address: 0x140208de0
// Ghidra name: FUN_140208de0
// ============ 0x140208de0 FUN_140208de0 (size=49) ============


void FUN_140208de0(ushort *param_1,char *param_2)



{

  char *pcVar1;

  uint uVar2;

  

  uVar2 = (uint)*param_1;

  if (uVar2 == (int)*param_2) {

    do {

      if ((short)uVar2 == 0) {

        return;

      }

      uVar2 = (uint)param_1[1];

      param_1 = param_1 + 1;

      pcVar1 = param_2 + 1;

      param_2 = param_2 + 1;

    } while (uVar2 == (int)*pcVar1);

  }

  return;

}




