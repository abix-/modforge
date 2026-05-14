// Address: 0x140229120
// Ghidra name: FUN_140229120
// ============ 0x140229120 FUN_140229120 (size=2689) ============


undefined8

FUN_140229120(longlong param_1,longlong *param_2,undefined8 param_3,longlong *param_4,

             tagPOINT param_5)



{

  BOOL BVar1;

  int iVar2;

  UINT UVar3;

  UINT UVar4;

  longlong lVar5;

  SIZE_T SVar6;

  LPVOID pvVar7;

  char *pcVar8;

  size_t sVar9;

  char *_Str;

  size_t sVar10;

  HDROP hDrop;

  LPWSTR lpszFile;

  UINT iFile;

  undefined8 local_res20;

  undefined8 in_stack_fffffffffffffe68;

  undefined4 uVar12;

  undefined8 uVar11;

  undefined2 local_178 [4];

  undefined8 local_170;

  undefined4 local_168;

  undefined4 local_164;

  undefined4 local_160;

  STGMEDIUM local_158;

  undefined1 local_138 [272];

  

  *(undefined4 *)param_5 = 1;

  param_5.y = (LONG)((ulonglong)param_4 >> 0x20);

  local_res20 = param_4;

  param_5.x = (LONG)param_4;

  BVar1 = ScreenToClient(*(HWND *)(param_1 + 0x18),&param_5);

  if (BVar1 == 0) {

    FUN_14012e280(7,". In Drop at %ld, %ld => nil, nil",(ulonglong)param_4 & 0xffffffff,

                  local_res20._4_4_);

  }

  else {

    in_stack_fffffffffffffe68 =

         CONCAT44((int)((ulonglong)in_stack_fffffffffffffe68 >> 0x20),

                  **(undefined4 **)(param_1 + 0x10));

    FUN_14012e280(7,". In Drop at %ld, %ld => window %u at %ld, %ld",(ulonglong)param_4 & 0xffffffff

                  ,local_res20._4_4_,in_stack_fffffffffffffe68,param_5.x,param_5.y);

    FUN_14022e000(*(undefined8 *)(param_1 + 0x10));

  }

  iVar2 = (**(code **)(*param_2 + 0x40))(param_2,1,&local_res20);

  FUN_14012e280(7,". In Drop for EnumFormatEtc, HRESULT is %08lx",iVar2);

  uVar12 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20);

  if (iVar2 == 0) {

    iVar2 = (**(code **)(*local_res20 + 0x18))(local_res20,1,local_178,0);

    while (uVar12 = (undefined4)((ulonglong)in_stack_fffffffffffffe68 >> 0x20), iVar2 == 0) {

      FUN_1402f94c0(local_138,0,0x101);

      lVar5 = FUN_140229f80(local_178[0],local_138,0x100);

      if (lVar5 == 0) {

        FUN_14012e280(7,". In Drop, Supported format is %08x, Predefined",local_178[0]);

      }

      else {

        FUN_14012e280(7,". In Drop, Supported format is %08x, \'%s\'",local_178[0],lVar5);

      }

      iVar2 = (**(code **)(*local_res20 + 0x18))(local_res20,1,local_178,0);

    }

  }

  local_178[0] = *(undefined2 *)(param_1 + 0x24);

  iFile = 0;

  local_170 = 0;

  local_168 = 1;

  local_164 = 0xffffffff;

  local_160 = 1;

  iVar2 = (**(code **)(*param_2 + 0x28))(param_2,local_178);

  if (-1 < iVar2) {

    FUN_14012e280(7,". In Drop File for QueryGetData, format %08x \'%s\', success",local_178[0],

                  "text/uri-list");

    iVar2 = (**(code **)(*param_2 + 0x18))(param_2,local_178,&local_158);

    uVar11 = CONCAT44(uVar12,iVar2);

    FUN_14012e280(7,". In Drop File for      GetData, format %08x \'%s\', HRESULT is %08lx",

                  local_178[0],"text/uri-list",uVar11);

    uVar12 = (undefined4)((ulonglong)uVar11 >> 0x20);

    if (iVar2 < 0) goto LAB_14022946c;

    SVar6 = GlobalSize(local_158.u.hGlobal);

    pvVar7 = GlobalLock(local_158.u.hGlobal);

    FUN_14012e280(7,". In Drop File for   GlobalLock, format %08x \'%s\', memory (%lu) %p",

                  local_178[0],"text/uri-list",SVar6 & 0xffffffff,pvVar7);

    if (pvVar7 == (LPVOID)0x0) goto LAB_140229448;

    lVar5 = FUN_1401841f0(SVar6 + 4);

    FUN_1402f8e20(lVar5,pvVar7,SVar6);

    *(undefined4 *)(lVar5 + SVar6) = 0;

    local_res20 = (longlong *)0x0;

    pcVar8 = (char *)FUN_140197d40(lVar5,&DAT_140357224,&local_res20);

    while (pcVar8 != (char *)0x0) {

      iVar2 = FUN_1401aacb0(pcVar8,pcVar8);

      if (-1 < iVar2) {

        sVar9 = strlen(pcVar8);

        FUN_14012e280(7,". In Drop File, file (%lu of %lu) \'%s\'",sVar9,SVar6 & 0xffffffff,pcVar8);

        FUN_14022dfd0(*(undefined8 *)(param_1 + 0x10),0,pcVar8);

      }

      pcVar8 = (char *)FUN_140197d40(0,&DAT_140357224,&local_res20);

    }

LAB_140229440:

    FUN_1401841e0(lVar5);

LAB_140229448:

    GlobalUnlock(local_158.u.hGlobal);

    ReleaseStgMedium(&local_158);

    FUN_14022dfa0(*(undefined8 *)(param_1 + 0x10));

    return 0;

  }

LAB_14022946c:

  local_178[0] = *(undefined2 *)(param_1 + 0x20);

  local_170 = 0;

  local_168 = 1;

  local_164 = 0xffffffff;

  local_160 = 1;

  iVar2 = (**(code **)(*param_2 + 0x28))(param_2,local_178);

  if (-1 < iVar2) {

    FUN_14012e280(7,". In Drop Text for QueryGetData, format %08x \'%s\', success",local_178[0],

                  "text/plain;charset=utf-8");

    iVar2 = (**(code **)(*param_2 + 0x18))(param_2,local_178,&local_158);

    uVar11 = CONCAT44(uVar12,iVar2);

    FUN_14012e280(7,". In Drop Text for      GetData, format %08x \'%s\', HRESULT is %08lx",

                  local_178[0],"text/plain;charset=utf-8",uVar11);

    uVar12 = (undefined4)((ulonglong)uVar11 >> 0x20);

    if (-1 < iVar2) {

      SVar6 = GlobalSize(local_158.u.hGlobal);

      pvVar7 = GlobalLock(local_158.u.hGlobal);

      FUN_14012e280(7,". In Drop Text for   GlobalLock, format %08x \'%s\', memory (%lu) %p",

                    local_178[0],"text/plain;charset=utf-8",SVar6 & 0xffffffff,pvVar7);

      if (pvVar7 == (LPVOID)0x0) goto LAB_140229448;

      lVar5 = FUN_1401841f0(SVar6 + 4);

      FUN_1402f8e20(lVar5,pvVar7,SVar6);

      *(undefined4 *)(lVar5 + SVar6) = 0;

      local_res20 = (longlong *)0x0;

      pcVar8 = (char *)FUN_140197d40(lVar5,&DAT_140357224,&local_res20);

      while (pcVar8 != (char *)0x0) {

        sVar9 = strlen(pcVar8);

        FUN_14012e280(7,". In Drop Text, text (%lu of %lu) \'%s\'",sVar9,SVar6 & 0xffffffff,pcVar8);

        FUN_14022e030(*(undefined8 *)(param_1 + 0x10),pcVar8);

        pcVar8 = (char *)FUN_140197d40(0,&DAT_140357224,&local_res20);

      }

      goto LAB_140229440;

    }

  }

  local_170 = 0;

  local_178[0] = 0xd;

  local_168 = 1;

  local_164 = 0xffffffff;

  local_160 = 1;

  iVar2 = (**(code **)(*param_2 + 0x28))(param_2,local_178);

  if (iVar2 < 0) {

LAB_14022982d:

    local_178[0] = 1;

    local_170 = 0;

    local_168 = 1;

    local_164 = 0xffffffff;

    local_160 = 1;

    iVar2 = (**(code **)(*param_2 + 0x28))(param_2,local_178);

    if (-1 < iVar2) {

      FUN_14012e280(7,". In Drop Text for QueryGetData, format %08x \'%s\', success",local_178[0],

                    "CF_TEXT");

      iVar2 = (**(code **)(*param_2 + 0x18))(param_2,local_178,&local_158);

      uVar11 = CONCAT44(uVar12,iVar2);

      FUN_14012e280(7,". In Drop Text for      GetData, format %08x \'%s\', HRESULT is %08lx",

                    local_178[0],"CF_TEXT",uVar11);

      uVar12 = (undefined4)((ulonglong)uVar11 >> 0x20);

      if (-1 < iVar2) {

        SVar6 = GlobalSize(local_158.u.hGlobal);

        pvVar7 = GlobalLock(local_158.u.hGlobal);

        FUN_14012e280(7,". In Drop Text for   GlobalLock, format %08x \'%s\', memory (%lu) %p",

                      local_178[0],"CF_TEXT",SVar6 & 0xffffffff,pvVar7);

        if (pvVar7 != (LPVOID)0x0) {

          _Str = (char *)FUN_1401841f0(SVar6 + 4);

          FUN_1402f8e20(_Str,pvVar7,SVar6);

          pcVar8 = _Str + SVar6;

          pcVar8[0] = '\0';

          pcVar8[1] = '\0';

          pcVar8[2] = '\0';

          pcVar8[3] = '\0';

          local_res20 = (longlong *)0x0;

          pcVar8 = (char *)FUN_140197d40(_Str,&DAT_140357224,&local_res20);

          while (pcVar8 != (char *)0x0) {

            sVar9 = strlen(pcVar8);

            FUN_14012e280(7,". In Drop Text, text (%lu of %lu) \'%s\'",sVar9,SVar6 & 0xffffffff,

                          pcVar8);

            FUN_14022e030(*(undefined8 *)(param_1 + 0x10),pcVar8);

            pcVar8 = (char *)FUN_140197d40(0,&DAT_140357224,&local_res20);

          }

          goto LAB_1402297e5;

        }

        goto LAB_1402297ed;

      }

    }

    local_170 = 0;

    local_178[0] = 0xf;

    local_168 = 1;

    local_164 = 0xffffffff;

    local_160 = 1;

    iVar2 = (**(code **)(*param_2 + 0x28))(param_2,local_178);

    if (-1 < iVar2) {

      FUN_14012e280(7,". In Drop File for QueryGetData, format %08x \'%s\', success",local_178[0],

                    "CF_HDROP");

      iVar2 = (**(code **)(*param_2 + 0x18))(param_2,local_178,&local_158);

      FUN_14012e280(7,". In Drop File for      GetData, format %08x \'%s\', HRESULT is %08lx",

                    local_178[0],"CF_HDROP",CONCAT44(uVar12,iVar2));

      if (-1 < iVar2) {

        SVar6 = GlobalSize(local_158.u.hGlobal);

        hDrop = GlobalLock(local_158.u.hGlobal);

        FUN_14012e280(7,". In Drop File for   GlobalLock, format %08x \'%s\', memory (%lu) %p",

                      local_178[0],"CF_HDROP",SVar6 & 0xffffffff,hDrop);

        UVar3 = DragQueryFileW(hDrop,0xffffffff,(LPWSTR)0x0,0);

        if (UVar3 != 0) {

          do {

            UVar4 = DragQueryFileW(hDrop,iFile,(LPWSTR)0x0,0);

            lpszFile = (LPWSTR)FUN_1401841f0((ulonglong)(UVar4 + 1) * 2);

            if (lpszFile != (LPWSTR)0x0) {

              UVar4 = DragQueryFileW(hDrop,iFile,lpszFile,UVar4 + 1);

              if (UVar4 != 0) {

                lVar5 = FUN_14012fd40(lpszFile);

                pcVar8 = (char *)FUN_140197820(&DAT_14039c6f0,"UTF-16LE",lpszFile,lVar5 * 2 + 2);

                sVar9 = strlen(pcVar8);

                FUN_14012e280(7,". In Drop File, file (%lu of %lu) \'%s\'",sVar9,SVar6 & 0xffffffff,

                              pcVar8);

                FUN_14022dfd0(*(undefined8 *)(param_1 + 0x10),0);

                FUN_1401841e0(pcVar8);

              }

              FUN_1401841e0(lpszFile);

            }

            iFile = iFile + 1;

          } while (iFile < UVar3);

        }

        GlobalUnlock(local_158.u.hGlobal);

        ReleaseStgMedium(&local_158);

        FUN_14022dfa0(*(undefined8 *)(param_1 + 0x10));

        return 0;

      }

    }

  }

  else {

    FUN_14012e280(7,". In Drop Text for QueryGetData, format %08x \'%s\', success",local_178[0],

                  "CF_UNICODETEXT");

    iVar2 = (**(code **)(*param_2 + 0x18))(param_2,local_178,&local_158);

    uVar11 = CONCAT44(uVar12,iVar2);

    FUN_14012e280(7,". In Drop Text for      GetData, format %08x \'%s\', HRESULT is %08lx",

                  local_178[0],"CF_UNICODETEXT",uVar11);

    uVar12 = (undefined4)((ulonglong)uVar11 >> 0x20);

    if (iVar2 < 0) goto LAB_14022982d;

    SVar6 = GlobalSize(local_158.u.hGlobal);

    pvVar7 = GlobalLock(local_158.u.hGlobal);

    FUN_14012e280(7,". In Drop Text for   GlobalLock, format %08x \'%s\', memory (%lu) %p",

                  local_178[0],"CF_UNICODETEXT",SVar6 & 0xffffffff,pvVar7);

    if (pvVar7 != (LPVOID)0x0) {

      lVar5 = FUN_14012fd40(pvVar7);

      _Str = (char *)FUN_140197820(&DAT_14039c6f0,"UTF-16LE",pvVar7,lVar5 * 2 + 2);

      if (_Str == (char *)0x0) goto LAB_1402297ed;

      sVar9 = strlen(_Str);

      FUN_14012e280(7,". In Drop Text for StringToUTF8, format %08x \'%s\', memory (%lu) %p",

                    local_178[0],"CF_UNICODETEXT",sVar9 & 0xffffffff,_Str);

      lVar5 = FUN_1401841f0(sVar9 + 4);

      FUN_1402f8e20(lVar5,_Str,sVar9);

      *(undefined4 *)(lVar5 + sVar9) = 0;

      local_res20 = (longlong *)0x0;

      pcVar8 = (char *)FUN_140197d40(lVar5,&DAT_140357224,&local_res20);

      while (pcVar8 != (char *)0x0) {

        sVar10 = strlen(pcVar8);

        FUN_14012e280(7,". In Drop Text, text (%lu of %lu) \'%s\'",sVar10,sVar9 & 0xffffffff,pcVar8)

        ;

        FUN_14022e030(*(undefined8 *)(param_1 + 0x10),pcVar8);

        pcVar8 = (char *)FUN_140197d40(0,&DAT_140357224,&local_res20);

      }

      FUN_1401841e0(lVar5);

LAB_1402297e5:

      FUN_1401841e0(_Str);

    }

LAB_1402297ed:

    GlobalUnlock(local_158.u.hGlobal);

    ReleaseStgMedium(&local_158);

  }

  FUN_14022dfa0(*(undefined8 *)(param_1 + 0x10));

  return 0;

}




