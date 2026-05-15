// Address: 0x14020b770
// Ghidra name: FUN_14020b770
// ============ 0x14020b770 FUN_14020b770 (size=289) ============


LRESULT FUN_14020b770(HWND param_1,UINT param_2,WPARAM param_3,HRAWINPUT param_4)



{

  UINT UVar1;

  LRESULT LVar2;

  longlong lVar3;

  uint local_88 [4];

  undefined1 local_78 [8];

  undefined8 local_70;

  undefined4 local_60;

  undefined1 local_58 [80];

  

  if (DAT_1403fd1b0 == '\0') {

LAB_14020b7b7:

    LVar2 = CallWindowProcW(DefWindowProcW_exref,param_1,param_2,param_3,(LPARAM)param_4);

  }

  else {

    FUN_140159d30();

    if (param_2 == 0xfe) {

      if (param_3 == 1) {

        FUN_140209a70(param_4);

      }

      else if ((param_3 == 2) && (lVar3 = FUN_140209f60(param_4), lVar3 != 0)) {

        FUN_140209e50(lVar3,1);

        FUN_14015bb10();

        return 0;

      }

    }

    else {

      if (param_2 != 0xff) {

        FUN_14015bb10();

        goto LAB_14020b7b7;

      }

      local_88[0] = 100;

      UVar1 = GetRawInputData(param_4,0x10000003,local_78,local_88,0x18);

      if (((0 < (int)UVar1) && (lVar3 = FUN_140209f60(local_70), lVar3 != 0)) &&

         (*(longlong *)(lVar3 + 0x48) != 0)) {

        FUN_14020a370(*(longlong *)(lVar3 + 0x48),local_58,local_60);

        FUN_14015bb10();

        return 0;

      }

    }

    FUN_14015bb10();

    LVar2 = 0;

  }

  return LVar2;

}




