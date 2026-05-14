// Address: 0x140223b20
// Ghidra name: FUN_140223b20
// ============ 0x140223b20 FUN_140223b20 (size=466) ============


ulonglong FUN_140223b20(undefined8 param_1,longlong param_2,HRGN param_3)



{

  undefined8 *puVar1;

  char cVar2;

  HRGN pHVar3;

  ulonglong uVar4;

  HRGN hRgn;

  undefined4 extraout_var;

  int iVar5;

  HRGN pHVar6;

  HRGN local_res10;

  undefined8 local_28;

  undefined8 local_20;

  

  puVar1 = *(undefined8 **)(param_2 + 0x188);

  hRgn = (HRGN)0x0;

  if (param_3 != (HRGN)0x0) {

    if ((param_3[2].unused != *(int *)(param_2 + 0x20)) ||

       (pHVar3 = param_3, pHVar6 = hRgn, param_3[3].unused != *(int *)(param_2 + 0x24))) {

      pHVar3 = (HRGN)FUN_140145e60(*(int *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x24),

                                   0x16862004);

      uVar4 = 0;

      if (pHVar3 == (HRGN)0x0) {

LAB_140223b98:

        return uVar4 & 0xffffffffffffff00;

      }

      cVar2 = FUN_140199be0(param_3,0,pHVar3,0,1);

      pHVar6 = pHVar3;

      if (cVar2 == '\0') {

        uVar4 = FUN_140146010(pHVar3);

        goto LAB_140223b98;

      }

    }

    local_28 = 0;

    local_20 = 0;

    uVar4 = FUN_14016e130(*puVar1);

    if ((uVar4 & 0x10) == 0) {

      FUN_14022a8c0(puVar1[1],&local_28,0);

    }

    hRgn = (HRGN)FUN_140223a10(pHVar3,-(int)local_28,-local_28._4_4_);

    local_res10 = hRgn;

    uVar4 = FUN_14016e130(*puVar1);

    if ((uVar4 & 0x10) == 0) {

      FUN_1402239a0(&local_res10,0,0,(int)local_20 + 1 + (pHVar3[2].unused - (int)local_28),

                    1 - local_28._4_4_);

      FUN_1402239a0(&local_res10,0,-local_28._4_4_,1 - (int)local_28,

                    (pHVar3[3].unused - local_28._4_4_) + 1);

      iVar5 = pHVar3[2].unused - (int)local_28;

      FUN_1402239a0(&local_res10,iVar5,-local_28._4_4_,(int)local_20 + 1 + iVar5,

                    (pHVar3[3].unused - local_28._4_4_) + 1);

      iVar5 = pHVar3[3].unused - local_28._4_4_;

      FUN_1402239a0(&local_res10,0,iVar5,(int)local_20 + 1 + (pHVar3[2].unused - (int)local_28),

                    local_20._4_4_ + 1 + iVar5);

      hRgn = local_res10;

    }

    if (pHVar6 != (HRGN)0x0) {

      FUN_140146010(pHVar6);

    }

  }

  iVar5 = SetWindowRgn((HWND)puVar1[1],hRgn,1);

  if (iVar5 == 0) {

    DeleteObject(hRgn);

    uVar4 = FUN_1401a9ed0("SetWindowRgn failed");

  }

  else {

    uVar4 = CONCAT71((int7)(CONCAT44(extraout_var,iVar5) >> 8),1);

  }

  return uVar4;

}




