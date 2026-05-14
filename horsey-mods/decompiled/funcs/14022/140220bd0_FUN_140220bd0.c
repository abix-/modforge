// Address: 0x140220bd0
// Ghidra name: FUN_140220bd0
// ============ 0x140220bd0 FUN_140220bd0 (size=327) ============


HGLOBAL FUN_140220bd0(short *param_1,ulonglong param_2,undefined4 *param_3)



{

  longlong lVar1;

  undefined4 uVar2;

  HGLOBAL hMem;

  LPVOID pvVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  

  if (((param_1 != (short *)0x0) && (0xe < param_2)) && (*param_1 == 0x4d42)) {

    uVar4 = (ulonglong)*(uint *)(param_1 + 0x11);

    lVar1 = (ulonglong)*(uint *)(param_1 + 7) + (ulonglong)*(uint *)(param_1 + 0x17) * 4;

    uVar2 = 0x11;

    if (*(uint *)(param_1 + 7) < 0x7c) {

      uVar2 = 8;

    }

    *param_3 = uVar2;

    uVar5 = (ulonglong)*(uint *)(param_1 + 5);

    if ((uVar5 < lVar1 + 0xeU) || (param_2 < uVar5 + uVar4)) {

      FUN_14012e850("Invalid BMP data");

      hMem = (HGLOBAL)0x0;

    }

    else {

      hMem = GlobalAlloc(2,uVar4 + lVar1);

      if (hMem == (HGLOBAL)0x0) {

        FUN_14012e770();

      }

      else {

        pvVar3 = GlobalLock(hMem);

        if (pvVar3 == (LPVOID)0x0) {

          FUN_1401a9ed0("GlobalLock()");

          GlobalFree(hMem);

          hMem = (HGLOBAL)0x0;

        }

        else {

          FUN_1402f8e20(pvVar3,param_1 + 7,lVar1);

          FUN_1402f8e20((longlong)pvVar3 + lVar1,uVar5 + (longlong)param_1,uVar4);

          GlobalUnlock(hMem);

        }

      }

    }

    return hMem;

  }

  FUN_14012e850("Invalid BMP data");

  return (HGLOBAL)0x0;

}




