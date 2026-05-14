// Address: 0x140240d00
// Ghidra name: FUN_140240d00
// ============ 0x140240d00 FUN_140240d00 (size=479) ============


void FUN_140240d00(longlong param_1,uint param_2,undefined4 *param_3)



{

  undefined4 uVar1;

  void *_Buf2;

  int iVar2;

  longlong lVar3;

  size_t _Size;

  longlong lVar4;

  

  lVar4 = (longlong)(int)param_2;

  uVar1 = *(undefined4 *)(param_1 + 0x84 + lVar4 * 0xc);

  (**(code **)(param_1 + 0x78))(uVar1);

  _Size = 0;

  if ((param_2 < 9) && ((0x158U >> (param_2 & 0x1f) & 1) != 0)) {

    _Size = 0x10;

  }

  else if (8 < (int)param_2) {

    _Size = 0x40;

  }

  if ((param_3 != (undefined4 *)0x0) &&

     ((_Buf2 = *(void **)(param_1 + 0x130 + lVar4 * 8), _Buf2 == (void *)0x0 ||

      (iVar2 = memcmp(param_3,_Buf2,_Size), iVar2 != 0)))) {

    if ((param_2 < 9) &&

       (((0x158U >> (param_2 & 0x1f) & 1) != 0 &&

        (iVar2 = (**(code **)(param_1 + 0x40))(uVar1,"texel_size"), -1 < iVar2)))) {

      (**(code **)(param_1 + 0x70))(iVar2,*param_3,param_3[1],param_3[2],param_3[3]);

    }

    if (8 < (int)param_2) {

      iVar2 = (**(code **)(param_1 + 0x40))(uVar1,"Yoffset");

      if (-1 < iVar2) {

        (**(code **)(param_1 + 0x68))(iVar2,*param_3,param_3[1],param_3[2]);

      }

      iVar2 = (**(code **)(param_1 + 0x40))(uVar1,"Rcoeff");

      if (-1 < iVar2) {

        (**(code **)(param_1 + 0x68))(iVar2,param_3[4],param_3[5],param_3[6]);

      }

      iVar2 = (**(code **)(param_1 + 0x40))(uVar1,"Gcoeff");

      if (-1 < iVar2) {

        (**(code **)(param_1 + 0x68))(iVar2,param_3[8],param_3[9],param_3[10]);

      }

      iVar2 = (**(code **)(param_1 + 0x40))(uVar1,"Bcoeff");

      if (-1 < iVar2) {

        (**(code **)(param_1 + 0x68))(iVar2,param_3[0xc],param_3[0xd],param_3[0xe]);

      }

    }

    lVar3 = *(longlong *)(param_1 + 0x130 + lVar4 * 8);

    if (lVar3 == 0) {

      lVar3 = FUN_1401841f0(_Size);

      *(longlong *)(param_1 + 0x130 + lVar4 * 8) = lVar3;

      if (lVar3 == 0) {

        return;

      }

    }

    FUN_1402f8e20(lVar3,param_3,_Size);

  }

  return;

}




