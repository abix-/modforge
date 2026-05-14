// Address: 0x14019ed50
// Ghidra name: FUN_14019ed50
// ============ 0x14019ed50 FUN_14019ed50 (size=346) ============


undefined8 FUN_14019ed50(longlong *param_1)



{

  byte bVar1;

  undefined1 uVar2;

  int iVar3;

  int iVar4;

  undefined8 uVar5;

  uint uVar6;

  

  param_1[0x8db] = 0;

  param_1[0x8dc] = 0;

  param_1[0x8e7] = 0;

  param_1[0x8e8] = 0;

  param_1[0x8f3] = 0;

  param_1[0x8f4] = 0;

  param_1[0x8ff] = 0;

  param_1[0x900] = 0;

  *(undefined4 *)(param_1 + 0x90d) = 0;

  iVar3 = FUN_14019ec00(param_1,0);

  if (iVar3 == 0) {

    return 0;

  }

  bVar1 = FUN_14019f370(param_1);

  uVar6 = (uint)bVar1;

  if (bVar1 != 0xd9) {

    do {

      if (uVar6 == 0xda) {

        iVar3 = FUN_1401a40b0(param_1);

        if (iVar3 == 0) {

          return 0;

        }

        iVar3 = FUN_1401a1ca0(param_1);

        if (iVar3 == 0) {

          return 0;

        }

        if ((char)param_1[0x905] == -1) {

          uVar2 = FUN_1401a4b30(param_1);

          *(undefined1 *)(param_1 + 0x905) = uVar2;

        }

        bVar1 = FUN_14019f370(param_1);

        uVar6 = (uint)bVar1;

        if (uVar6 - 0xd0 < 8) goto LAB_14019ee65;

      }

      else {

        if (uVar6 == 0xdc) {

          iVar3 = FUN_14019f260(*param_1);

          iVar4 = FUN_14019f260(*param_1);

          if ((iVar3 != 4) || (iVar4 != *(int *)(*param_1 + 4))) {

            uVar5 = FUN_14019f050("Corrupt JPEG");

            return uVar5;

          }

        }

        else {

          iVar3 = FUN_1401a3830(param_1,uVar6);

          if (iVar3 == 0) {

            return 1;

          }

        }

LAB_14019ee65:

        bVar1 = FUN_14019f370(param_1);

        uVar6 = (uint)bVar1;

      }

    } while (uVar6 != 0xd9);

  }

  if ((int)param_1[0x906] != 0) {

    FUN_1401a1480(param_1);

  }

  return 1;

}




