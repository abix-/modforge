// Address: 0x14008ded0
// Ghidra name: FUN_14008ded0
// ============ 0x14008ded0 FUN_14008ded0 (size=754) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14008ded0(longlong param_1)



{

  char *_Str;

  longlong *plVar1;

  float fVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  undefined4 uVar5;

  longlong lVar6;

  size_t sVar7;

  int iVar8;

  int iVar9;

  longlong local_res8;

  longlong local_res10;

  undefined8 in_stack_ffffffffffffff98;

  ulonglong local_58 [8];

  

  FUN_1400d01d0(param_1,"Clide",5,DAT_1403d9f2c);

  *(undefined4 *)(*(longlong *)(param_1 + 0x148) + 0x284) = 0xb;

  uVar5 = DAT_14030374c;

  fVar2 = DAT_140303354;

  iVar8 = 0x58;

  iVar9 = 0x17;

  do {

    lVar6 = FUN_1400cc9d0(param_1,iVar9,(float)iVar8 * fVar2,uVar5);

    *(undefined1 *)(lVar6 + 0x10) = 0;

    iVar8 = iVar8 + 0x14;

    iVar9 = iVar9 + 1;

  } while (iVar8 < 0x80);

  *(undefined4 *)(param_1 + 0x264) = 0;

  uVar4 = _UNK_140304cb8;

  uVar3 = _DAT_140304cb0;

  iVar9 = 0;

  iVar8 = 0;

  do {

    uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);

    if (iVar8 < 8) {

      local_res10 = FUN_1402c704c(0x498);

      if (local_res10 == 0) {

        lVar6 = 0;

      }

      else {

        lVar6 = FUN_1400aac60(local_res10);

      }

      local_58[1] = 0;

      local_58[2] = uVar3;

      local_58[3] = uVar4;

      local_58[0] = (ulonglong)(uint3)DAT_140303b54;

      local_res8 = lVar6;

      FUN_1400c6580(3);

      FUN_1400b2ee0(lVar6,local_58);

      if (0xf < local_58[3]) {

        if (0xfff < local_58[3] + 1) {

          if (0x1f < (local_58[0] - *(longlong *)(local_58[0] - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

        }

        FUN_1402c7088();

      }

      in_stack_ffffffffffffff98 = CONCAT44(uVar5,0xffffffff);

      uVar5 = FUN_1400c7600(0,3,0xffffffff,0xffffffff,in_stack_ffffffffffffff98);

      *(undefined4 *)(lVar6 + 0x1f8) = uVar5;

      *(undefined1 *)(lVar6 + 0x160) = 1;

      *(undefined4 *)(lVar6 + 0x220) =

           *(undefined4 *)(&DAT_14030b7d0 + (longlong)*(int *)(param_1 + 0x264) * 4);

      if (*(int *)(param_1 + 0x264) == 7) {

        *(undefined1 *)(lVar6 + 0x2e9) = 0;

        *(undefined1 *)(lVar6 + 0x3d9) = 0;

        *(undefined1 *)(lVar6 + 0x2cb) = 0;

        *(undefined1 *)(lVar6 + 0x3bb) = 0;

        FUN_1400b3070(lVar6);

      }

      _Str = (&PTR_s_Hyundai_1403d9ee0)[*(int *)(param_1 + 0x264)];

      local_58[0] = 0;

      local_58[1] = 0;

      local_58[2] = 0;

      local_58[3] = 0;

      sVar7 = strlen(_Str);

      FUN_140027e30(local_58,_Str,sVar7);

      FUN_1400cf950(param_1,lVar6);

      if (0xf < local_58[3]) {

        if (0xfff < local_58[3] + 1) {

          if (0x1f < (local_58[0] - *(longlong *)(local_58[0] - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

        }

        FUN_1402c7088();

      }

      plVar1 = *(longlong **)(param_1 + 0x138);

      if (plVar1 == *(longlong **)(param_1 + 0x140)) {

        FUN_140030680(param_1 + 0x130,plVar1,&local_res8);

      }

      else {

        *plVar1 = lVar6;

        *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

      }

      *(int *)(param_1 + 0x264) = *(int *)(param_1 + 0x264) + 1;

      iVar8 = *(int *)(param_1 + 0x264);

    }

    iVar9 = iVar9 + 1;

  } while (iVar9 < 2);

  return;

}




