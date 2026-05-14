// Address: 0x140026080
// Ghidra name: FUN_140026080
// ============ 0x140026080 FUN_140026080 (size=562) ============


bool FUN_140026080(longlong *param_1,FILE *param_2,undefined4 param_3)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  undefined *puVar4;

  int iVar5;

  char *_DstBuf;

  size_t sVar6;

  char *pcVar7;

  size_t _ElementSize;

  longlong lVar8;

  char *pcVar9;

  

  puVar4 = PTR_s_Failed_to_open_file_14039a3c0;

  if (param_2 == (FILE *)0x0) {

    if ((char)param_1[0xd] != '\0') {

      return false;

    }

    lVar8 = -1;

    *(undefined1 *)(param_1 + 0xd) = 1;

    *(undefined4 *)((longlong)param_1 + 0x6c) = 2;

    do {

      lVar8 = lVar8 + 1;

    } while (puVar4[lVar8] != '\0');

  }

  else {

    FUN_1400250c0();

    param_1[1] = -1;

    FUN_1402cea4c(param_2,0,2);

    iVar5 = FUN_1402cf00c(param_2);

    _ElementSize = (size_t)iVar5;

    FUN_1402cea4c(param_2,0,0);

    puVar4 = PTR_s_Error_document_empty__14039a410;

    if (iVar5 < 1) {

      if ((char)param_1[0xd] != '\0') {

        return false;

      }

      lVar8 = -1;

      *(undefined1 *)(param_1 + 0xd) = 1;

      *(undefined4 *)((longlong)param_1 + 0x6c) = 0xc;

      do {

        lVar8 = lVar8 + 1;

      } while (puVar4[lVar8] != '\0');

    }

    else {

      _DstBuf = (char *)thunk_FUN_1402c704c(_ElementSize + 1);

      *_DstBuf = '\0';

      sVar6 = fread(_DstBuf,_ElementSize,1,param_2);

      if (sVar6 == 1) {

        pcVar9 = _DstBuf + _ElementSize;

        *pcVar9 = '\0';

        cVar1 = *_DstBuf;

        pcVar2 = _DstBuf;

        pcVar3 = _DstBuf;

        while (cVar1 != '\0') {

          if (pcVar9 <= pcVar3) {

            FID_conflict__assert(L"p < (buf+length)",L"C:\\dev\\tinyxml\\tinyxml.cpp",0x3f6);

          }

          if (pcVar9 < pcVar2) {

            FID_conflict__assert(L"q <= (buf+length)",L"C:\\dev\\tinyxml\\tinyxml.cpp",0x3f7);

          }

          if (pcVar3 < pcVar2) {

            FID_conflict__assert(L"q <= p",L"C:\\dev\\tinyxml\\tinyxml.cpp",0x3f8);

          }

          pcVar7 = pcVar3 + 1;

          if (*pcVar3 == '\r') {

            *pcVar2 = '\n';

            if (*pcVar7 == '\n') {

              pcVar7 = pcVar3 + 2;

            }

          }

          else {

            *pcVar2 = *pcVar3;

          }

          pcVar2 = pcVar2 + 1;

          pcVar3 = pcVar7;

          cVar1 = *pcVar7;

        }

        if (pcVar9 < pcVar2) {

          FID_conflict__assert(L"q <= (buf+length)",L"C:\\dev\\tinyxml\\tinyxml.cpp",0x405);

        }

        *pcVar2 = '\0';

        (**(code **)(*param_1 + 0x10))(param_1,_DstBuf,0,param_3);

        FUN_1402c7088(_DstBuf);

        return (char)param_1[0xd] == '\0';

      }

      FUN_1402c7088(_DstBuf);

      puVar4 = PTR_s_Failed_to_open_file_14039a3c0;

      if ((char)param_1[0xd] != '\0') {

        return false;

      }

      lVar8 = -1;

      *(undefined1 *)(param_1 + 0xd) = 1;

      *(undefined4 *)((longlong)param_1 + 0x6c) = 2;

      do {

        lVar8 = lVar8 + 1;

      } while (puVar4[lVar8] != '\0');

    }

  }

  FUN_140027f50(param_1 + 0xe);

  *(undefined8 *)((longlong)param_1 + 0x94) = 0xffffffffffffffff;

  return false;

}




