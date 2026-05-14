// Address: 0x14006a140
// Ghidra name: FUN_14006a140
// ============ 0x14006a140 FUN_14006a140 (size=717) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14006a140(longlong param_1)



{

  char *_Str;

  longlong *plVar1;

  float fVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  float fVar5;

  undefined4 uVar6;

  int iVar7;

  longlong lVar8;

  size_t sVar9;

  int iVar10;

  longlong lVar11;

  undefined4 local_res10;

  undefined4 local_res14;

  longlong local_res18;

  longlong local_res20;

  undefined8 in_stack_ffffffffffffff78;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  ulonglong uStack_60;

  

  fVar5 = DAT_14039ca44;

  uVar4 = _UNK_140304088;

  uVar3 = _DAT_140304080;

  fVar2 = DAT_14030335c;

  iVar10 = 0;

  lVar11 = 0;

  do {

    uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);

    local_res20 = FUN_1402c704c(0x498);

    if (local_res20 == 0) {

      lVar8 = 0;

    }

    else {

      lVar8 = FUN_1400aac60(local_res20);

    }

    *(undefined4 *)(lVar8 + 0xc0) = DAT_1403d93a8;

    uStack_70 = 0;

    local_68 = uVar3;

    uStack_60 = uVar4;

    local_78 = (ulonglong)CONCAT14(s_human_140303b0c[4],s_human_140303b0c._0_4_);

    local_res18 = lVar8;

    FUN_1400c6580(5);

    FUN_1400b2ee0(lVar8,&local_78);

    if (0xf < uStack_60) {

      if (0xfff < uStack_60 + 1) {

        if (0x1f < (local_78 - *(longlong *)(local_78 - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    local_res10 = (&DAT_14030a068)[lVar11 * 2];

    local_res14 = (&DAT_14030a06c)[lVar11 * 2];

    FUN_1400b6610(lVar8,&local_res10);

    in_stack_ffffffffffffff78 = CONCAT44(uVar6,0xffffffff);

    uVar6 = FUN_1400c7600(0,7,0xffffffff,0xffffffff,in_stack_ffffffffffffff78);

    *(undefined4 *)(lVar8 + 0x1f8) = uVar6;

    iVar7 = FUN_1400c6580(0x1e);

    _Str = (&PTR_DAT_1403d9280)[iVar7];

    local_78 = 0;

    uStack_70 = 0;

    local_68 = 0;

    uStack_60 = 0;

    sVar9 = strlen(_Str);

    FUN_140027e30(&local_78,_Str,sVar9);

    FUN_1400cf950(param_1,lVar8);

    if (0xf < uStack_60) {

      if (0xfff < uStack_60 + 1) {

        if (0x1f < (local_78 - *(longlong *)(local_78 + -8)) - 8) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    *(undefined1 *)(lVar8 + 0x160) = 1;

    *(undefined4 *)(lVar8 + 0x1cc) = 0xffffffff;

    *(bool *)(lVar8 + 0x1a) = 0 < iVar10;

    plVar1 = *(longlong **)(param_1 + 0x138);

    if (plVar1 == *(longlong **)(param_1 + 0x140)) {

      FUN_140030680(param_1 + 0x130,plVar1,&local_res18);

    }

    else {

      *plVar1 = lVar8;

      *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

    }

    if (0 < lVar11) {

      FUN_1400cc9d0(param_1,3,(float)(&DAT_14030a068)[lVar11 * 2] + fVar5,

                    (float)(&DAT_14030a06c)[lVar11 * 2] + fVar2);

    }

    iVar10 = iVar10 + 1;

    lVar11 = lVar11 + 1;

  } while (lVar11 < 3);

  return;

}




