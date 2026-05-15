// Address: 0x140183cd0
// Ghidra name: FUN_140183cd0
// ============ 0x140183cd0 FUN_140183cd0 (size=146) ============


void FUN_140183cd0(char *param_1)



{

  char cVar1;

  int iVar2;

  undefined4 local_88 [2];

  undefined8 local_80;

  undefined4 local_78;

  longlong local_70;

  

  if (DAT_1403fc6e0 != (undefined4 *)0x0) {

    cVar1 = FUN_140172fc0();

    if (((cVar1 != '\0') && (param_1 != (char *)0x0)) && (*param_1 != '\0')) {

      iVar2 = FUN_140190320(*param_1);

      if (iVar2 == 0) {

        cVar1 = FUN_140139420();

        if (cVar1 != '\0') {

          local_88[0] = 0x303;

          local_80 = 0;

          if (DAT_1403fc6e0 == (undefined4 *)0x0) {

            local_78 = 0;

          }

          else {

            local_78 = *DAT_1403fc6e0;

          }

          local_70 = FUN_1401392f0(param_1);

          if (local_70 != 0) {

            FUN_14013b140(local_88);

          }

        }

      }

    }

  }

  return;

}




