// Address: 0x14016d920
// Ghidra name: FUN_14016d920
// ============ 0x14016d920 FUN_14016d920 (size=310) ============


longlong FUN_14016d920(int *param_1)



{

  int iVar1;

  longlong lVar2;

  uint uVar3;

  int iVar4;

  longlong lVar5;

  int local_48;

  int iStack_44;

  int iStack_40;

  int iStack_3c;

  int local_38;

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  undefined8 local_28;

  

  if ((param_1[2] < 1) || (param_1[3] < 1)) {

    return 0;

  }

  local_48 = *param_1;

  iStack_44 = param_1[1];

  iStack_40 = param_1[2];

  iStack_3c = param_1[3];

  local_38 = param_1[4];

  iStack_34 = param_1[5];

  iStack_30 = param_1[6];

  iStack_2c = param_1[7];

  local_28 = *(undefined8 *)(param_1 + 8);

  if (local_48 == 0) {

    local_48 = FUN_14016dba0();

  }

  FUN_14016bc10(&local_48);

  uVar3 = 0;

  lVar2 = FUN_14016dd00(local_48);

  if (lVar2 != 0) {

    FUN_140173170(lVar2);

    iVar4 = 0;

    if (0 < *(int *)(lVar2 + 0x14)) {

      do {

        iVar1 = memcmp(&local_48,(void *)(*(longlong *)(lVar2 + 0x18) + (longlong)iVar4 * 0x28),0x28

                      );

        if (iVar1 == 0) {

          lVar5 = *(longlong *)(lVar2 + 0x18) + (longlong)iVar4 * 0x28;

          if (lVar5 != 0) {

            return lVar5;

          }

          break;

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < *(int *)(lVar2 + 0x14));

    }

    iVar4 = *(int *)(lVar2 + 0x14);

    if (0 < iVar4) {

      lVar2 = *(longlong *)(lVar2 + 0x18);

      do {

        lVar5 = lVar2 + (ulonglong)uVar3 * 0x28;

        iVar1 = FUN_140174340(&local_48,lVar5);

        if (iVar1 == 0) {

          return lVar5;

        }

        uVar3 = uVar3 + 1;

      } while ((int)uVar3 < iVar4);

    }

  }

  return 0;

}




