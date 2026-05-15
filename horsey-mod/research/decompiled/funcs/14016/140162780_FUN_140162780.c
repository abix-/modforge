// Address: 0x140162780
// Ghidra name: FUN_140162780
// ============ 0x140162780 FUN_140162780 (size=331) ============


void FUN_140162780(uint param_1)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  uint *puVar4;

  uint uVar5;

  undefined8 local_88;

  undefined8 uStack_80;

  ulonglong local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  iVar2 = FUN_140161250();

  if (-1 < iVar2) {

    iVar1 = DAT_1403fc328 + -1;

    if (iVar2 != iVar1) {

      FUN_1402f8e20(DAT_1403fc330 + (longlong)iVar2 * 4,DAT_1403fc330 + (longlong)(iVar2 + 1) * 4,

                    (longlong)((DAT_1403fc328 - iVar2) + -1) << 2);

    }

    DAT_1403fc328 = iVar1;

    lVar3 = FUN_1401611a0();

    uVar5 = 0;

    if (0 < *(int *)(lVar3 + 0x100)) {

      puVar4 = *(uint **)(lVar3 + 0x108);

      do {

        if (*puVar4 == param_1) {

          FUN_1401841e0(*(undefined8 *)(puVar4 + 4));

          if (uVar5 != *(int *)(lVar3 + 0x100) - 1U) {

            FUN_1402f8e20(*(longlong *)(lVar3 + 0x108) + (longlong)(int)uVar5 * 0x18,

                          *(longlong *)(lVar3 + 0x108) + (longlong)(int)(uVar5 + 1) * 0x18,

                          (longlong)(int)(~uVar5 + *(int *)(lVar3 + 0x100)) * 0x18);

          }

          *(int *)(lVar3 + 0x100) = *(int *)(lVar3 + 0x100) + -1;

          break;

        }

        uVar5 = uVar5 + 1;

        puVar4 = puVar4 + 6;

      } while ((int)uVar5 < *(int *)(lVar3 + 0x100));

    }

    if (DAT_1403fc32c != '\0') {

      uStack_80 = 0;

      local_88 = 0x405;

      uStack_70 = 0;

      local_78 = (ulonglong)param_1;

      local_68 = 0;

      uStack_60 = 0;

      local_58 = 0;

      uStack_50 = 0;

      local_48 = 0;

      uStack_40 = 0;

      local_38 = 0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_18 = 0;

      uStack_10 = 0;

      FUN_14013b140(&local_88);

    }

  }

  return;

}




