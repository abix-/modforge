// Address: 0x14008e370
// Ghidra name: FUN_14008e370
// ============ 0x14008e370 FUN_14008e370 (size=567) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14008e370(longlong param_1)



{

  char *_Str;

  longlong *plVar1;

  undefined4 uVar2;

  longlong lVar3;

  size_t sVar4;

  longlong local_res8;

  undefined8 in_stack_ffffffffffffffc8;

  ulonglong local_28 [4];

  

  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  if (*(int *)(param_1 + 0x264) < 8) {

    local_res8 = FUN_1402c704c(0x498);

    if (local_res8 == 0) {

      lVar3 = 0;

    }

    else {

      lVar3 = FUN_1400aac60(local_res8);

    }

    local_28[1] = 0;

    local_28[2] = _DAT_140304cb0;

    local_28[3] = _UNK_140304cb8;

    local_28[0] = (ulonglong)(uint3)DAT_140303b54;

    local_res8 = lVar3;

    FUN_1400c6580(3);

    FUN_1400b2ee0(lVar3,local_28);

    if (0xf < local_28[3]) {

      if (0xfff < local_28[3] + 1) {

        if (0x1f < (local_28[0] - *(longlong *)(local_28[0] - 8)) - 8) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

      }

      FUN_1402c7088();

    }

    uVar2 = FUN_1400c7600(0,3,0xffffffff,0xffffffff,CONCAT44(uVar2,0xffffffff));

    *(undefined4 *)(lVar3 + 0x1f8) = uVar2;

    *(undefined1 *)(lVar3 + 0x160) = 1;

    *(undefined4 *)(lVar3 + 0x220) =

         *(undefined4 *)(&DAT_14030b7d0 + (longlong)*(int *)(param_1 + 0x264) * 4);

    if (*(int *)(param_1 + 0x264) == 7) {

      *(undefined1 *)(lVar3 + 0x2e9) = 0;

      *(undefined1 *)(lVar3 + 0x3d9) = 0;

      *(undefined1 *)(lVar3 + 0x2cb) = 0;

      *(undefined1 *)(lVar3 + 0x3bb) = 0;

      FUN_1400b3070(lVar3);

    }

    _Str = (&PTR_s_Hyundai_1403d9ee0)[*(int *)(param_1 + 0x264)];

    local_28[0] = 0;

    local_28[1] = 0;

    local_28[2] = 0;

    local_28[3] = 0;

    sVar4 = strlen(_Str);

    FUN_140027e30(local_28,_Str,sVar4);

    FUN_1400cf950(param_1,lVar3);

    if (0xf < local_28[3]) {

      if (0xfff < local_28[3] + 1) {

        if (0x1f < (local_28[0] - *(longlong *)(local_28[0] - 8)) - 8) {

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

      *plVar1 = lVar3;

      *(longlong *)(param_1 + 0x138) = *(longlong *)(param_1 + 0x138) + 8;

    }

    *(int *)(param_1 + 0x264) = *(int *)(param_1 + 0x264) + 1;

  }

  return;

}




