// Address: 0x1401926f0
// Ghidra name: FUN_1401926f0
// ============ 0x1401926f0 FUN_1401926f0 (size=665) ============


longlong FUN_1401926f0(short param_1,short param_2)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  short *psVar4;

  longlong lVar5;

  HANDLE hObject;

  longlong lVar6;

  wchar_t *pwVar7;

  short *psVar8;

  longlong lVar9;

  longlong lVar10;

  longlong lVar11;

  undefined4 local_res18 [2];

  undefined8 local_res20;

  undefined4 uVar12;

  undefined2 uVar13;

  undefined4 local_98;

  short local_94;

  short local_92;

  undefined1 local_88 [16];

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  

  lVar6 = 0;

  lVar10 = 0;

  psVar4 = (short *)0x0;

  iVar2 = FUN_140192a10();

  if (iVar2 < 0) {

    return 0;

  }

  (*DAT_1403fcc48)(local_88);

  do {

    iVar2 = (*DAT_1403fccd8)(local_res18,local_88,0,0);

    lVar9 = lVar6;

    if (iVar2 != 0) {

      pwVar7 = L"Failed to get size of HID device interface list";

      goto LAB_14019295f;

    }

    FUN_1401841e0(psVar4);

    psVar4 = (short *)FUN_1401841a0(local_res18[0],2);

    if (psVar4 == (short *)0x0) {

      FUN_140196b40(L"Failed to allocate memory for HID device interface list");

      return 0;

    }

    uVar12 = 0;

    iVar2 = (*DAT_1403fcce0)(local_88,0,psVar4,local_res18[0],0);

    if (iVar2 == 0) {

      psVar8 = psVar4;

      if (*psVar4 != 0) goto LAB_1401927d0;

      goto LAB_14019292a;

    }

  } while (iVar2 == 0x1a);

  pwVar7 = L"Failed to get HID device interface list";

LAB_14019295f:

  FUN_140196b40(pwVar7);

LAB_140192964:

  FUN_1401841e0(psVar4);

  return lVar9;

LAB_1401927d0:

  do {

    lVar5 = FUN_14012ffb0(psVar8,L"&IG_");

    lVar9 = lVar6;

    lVar11 = lVar10;

    if ((lVar5 == 0) &&

       (hObject = (HANDLE)FUN_1401967f0(psVar8,0), hObject != (HANDLE)0xffffffffffffffff)) {

      local_98 = 0xc;

      cVar1 = (*DAT_1403fcc50)(hObject,&local_98);

      uVar13 = (undefined2)((uint)uVar12 >> 0x10);

      if (cVar1 != '\0') {

        uVar3 = FUN_140195800(psVar8);

        local_res20 = 0;

        local_78 = 0;

        uStack_70 = 0;

        local_68 = 0;

        uStack_60 = 0;

        local_58 = 0;

        uStack_50 = 0;

        local_48 = 0;

        uStack_40 = 0;

        cVar1 = (*DAT_1403fcc90)(hObject,&local_res20);

        if (cVar1 != '\0') {

          (*DAT_1403fcca0)(local_res20,&local_78);

          (*DAT_1403fcc98)(local_res20);

        }

        uVar12 = CONCAT22(uVar13,(undefined2)local_78);

        cVar1 = FUN_140192dc0(uVar3,local_94,local_92,local_78._2_2_,uVar12,0);

        if ((((cVar1 == '\0') && ((param_1 == 0 || (local_94 == param_1)))) &&

            ((param_2 == 0 || (local_92 == param_2)))) &&

           (((iVar2 = FUN_140195970(), iVar2 == 0 &&

             (lVar5 = FUN_140195f10(psVar8,hObject), lVar5 != 0)) &&

            (lVar9 = lVar5, lVar11 = lVar5, lVar10 != 0)))) {

          *(longlong *)(lVar10 + 0x38) = lVar5;

          lVar9 = lVar6;

        }

      }

      CloseHandle(hObject);

    }

    lVar6 = FUN_14012fd40(psVar8);

    psVar8 = psVar8 + lVar6 + 1;

    lVar6 = lVar9;

    lVar10 = lVar11;

  } while (*psVar8 != 0);

  if (lVar9 != 0) goto LAB_140192964;

LAB_14019292a:

  if ((param_1 == 0) && (param_2 == 0)) {

    pwVar7 = L"No HID devices found in the system.";

  }

  else {

    pwVar7 = L"No HID devices with requested VID/PID found in the system.";

  }

  goto LAB_14019295f;

}




