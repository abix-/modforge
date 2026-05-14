// Address: 0x1400fce70
// Ghidra name: FUN_1400fce70
// ============ 0x1400fce70 FUN_1400fce70 (size=860) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400fce70(longlong param_1,undefined8 param_2)



{

  undefined4 uVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  longlong lVar4;

  undefined8 uVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  undefined8 local_138;

  undefined8 uStack_130;

  undefined8 local_128;

  ulonglong uStack_120;

  longlong local_118 [2];

  longlong local_108;

  undefined8 local_f8;

  undefined8 uStack_f0;

  undefined8 local_e8;

  undefined8 uStack_e0;

  undefined8 local_d8;

  undefined8 uStack_d0;

  undefined8 local_c8;

  undefined8 uStack_c0;

  undefined8 local_b8;

  undefined8 uStack_b0;

  undefined8 local_a8;

  undefined8 uStack_a0;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  

  if (0.0 < *(float *)(param_1 + 0x39c)) {

    *(undefined1 *)(param_1 + 0x41c) = 1;

    lVar4 = *(longlong *)(param_1 + 0x300);

    uVar1 = *(undefined4 *)(lVar4 + 0x2c);

    *(undefined4 *)(param_1 + 0x394) = *(undefined4 *)(lVar4 + 0x28);

    *(undefined4 *)(param_1 + 0x398) = uVar1;

    fVar8 = *(float *)(param_1 + 0x3a0) - *(float *)(lVar4 + 0x34) * DAT_14039ca34;

    fVar7 = *(float *)(param_1 + 0x39c) - 0.0;

    *(float *)(lVar4 + 0x28) = fVar7;

    *(float *)(*(longlong *)(param_1 + 0x300) + 0x2c) = fVar8;

    *(undefined1 *)(*(longlong *)(param_1 + 0x300) + 0xac) = 1;

    if (*(int *)(param_1 + 0x35c) != 0) {

      DAT_1403ed968 = 1;

      *(float *)(param_1 + 0x354) =

           (fVar7 - *(float *)(param_1 + 0x394)) + *(float *)(param_1 + 0x354);

      *(float *)(param_1 + 0x358) =

           (fVar8 - *(float *)(param_1 + 0x398)) + *(float *)(param_1 + 0x358);

      FUN_140107660();

    }

    local_f8 = _DAT_1403132c0;

    uStack_f0 = _UNK_1403132c8;

    local_e8 = _DAT_1403132b0;

    uStack_e0 = _UNK_1403132b8;

    local_d8 = _DAT_1403132a0;

    uStack_d0 = _UNK_1403132a8;

    local_c8 = _DAT_140313230;

    uStack_c0 = _UNK_140313238;

    local_b8 = _DAT_140313240;

    uStack_b0 = _UNK_140313248;

    local_a8 = _DAT_140313260;

    uStack_a0 = _UNK_140313268;

    local_98 = _DAT_140313250;

    uStack_90 = _UNK_140313258;

    local_88 = _DAT_140313290;

    uStack_80 = _UNK_140313298;

    local_78 = _DAT_140313280;

    uStack_70 = _UNK_140313288;

    local_68 = _DAT_140313270;

    uStack_60 = _UNK_140313278;

    FUN_1400c5d10(local_118,0x14);

    uVar3 = _UNK_140304088;

    uVar2 = _DAT_140304080;

    iVar6 = 0;

    do {

      lVar4 = FUN_1402c704c(0x498);

      if (lVar4 == 0) {

        uVar5 = 0;

      }

      else {

        uVar5 = FUN_1400aac60(lVar4);

      }

      uStack_130 = 0;

      local_128 = uVar2;

      uStack_120 = uVar3;

      local_138 = (ulonglong)CONCAT14(DAT_140313074,DAT_140313070);

      FUN_1400b2ee0(uVar5,&local_138);

      if (0xf < uStack_120) {

        if (0xfff < uStack_120 + 1) {

          if (0x1f < (local_138 - *(longlong *)(local_138 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

        }

        FUN_1402c7088();

      }

      FUN_1400b3650(uVar5,param_2);

      FUN_140100e30(param_1,uVar5);

      iVar6 = iVar6 + 1;

    } while (iVar6 < 0x14);

    FUN_140104370(param_1);

    *(undefined4 *)(param_1 + 0x268) = 1;

    *(undefined4 *)(param_1 + 0x114) = 0x3f800000;

    if (local_118[0] != 0) {

      if (0xfff < (local_108 - local_118[0] & 0xfffffffffffffffcU)) {

        if (0x1f < (local_118[0] - *(longlong *)(local_118[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

  }

  return;

}




