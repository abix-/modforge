// Address: 0x14027ab70
// Ghidra name: FUN_14027ab70
// ============ 0x14027ab70 FUN_14027ab70 (size=428) ============


byte FUN_14027ab70(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  bool bVar4;

  undefined1 local_res8 [8];

  char local_58;

  byte local_57;

  char local_56;

  char local_55;

  undefined1 local_54 [13];

  undefined1 local_47;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  lVar3 = 0;

  if (0 < *(int *)(param_1 + 0x8c)) {

    lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  }

  iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_58,0x40,0);

  do {

    if (iVar2 < 1) {

      if ((iVar2 < 0) && (0 < *(int *)(param_1 + 0x8c))) {

        FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

      }

      return (byte)((uint)iVar2 >> 0x1f) ^ 1;

    }

    if (iVar2 == 2) {

      if (local_58 == '\b') {

        bVar4 = (local_57 & 0x80) != 0;

        if (bVar4 != (bool)*(char *)(lVar1 + 8)) {

          *(bool *)(lVar1 + 8) = bVar4;

          if ((local_57 & 0x80) == 0) {

            if (0 < *(int *)(param_1 + 0x8c)) {

              FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

            }

          }

          else {

            FUN_140208110(param_1,local_res8);

          }

        }

      }

    }

    else if ((iVar2 == 0x1d) && (local_58 == '\0')) {

      if (local_57 == 0xf) {

        if ((local_56 == '\0') && (local_55 == -0x10)) {

          if (lVar3 != 0) {

            FUN_14027b080(lVar3,local_47);

          }

        }

        else {

LAB_14027ac91:

          if (((local_57 & 1) != 0) && (lVar3 != 0)) {

            FUN_14027ad40(lVar3,*(undefined8 *)(param_1 + 0x80),lVar1,local_54,0x19);

          }

        }

      }

      else {

        if (((local_57 != 0) || (local_56 != '\0')) || (local_55 != '\x13')) goto LAB_14027ac91;

        if (lVar3 != 0) {

          FUN_14027b080(lVar3,local_54[0]);

        }

      }

    }

    iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_58,0x40,0);

  } while( true );

}




