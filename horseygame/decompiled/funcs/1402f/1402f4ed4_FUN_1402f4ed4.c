// Address: 0x1402f4ed4
// Ghidra name: FUN_1402f4ed4
// ============ 0x1402f4ed4 FUN_1402f4ed4 (size=186) ============


undefined8 FUN_1402f4ed4(uint param_1)



{

  int iVar1;

  ulonglong uVar2;

  undefined4 *puVar3;

  DWORD nStdHandle;

  

  if ((-1 < (int)param_1) && (param_1 < DAT_1403ff560)) {

    uVar2 = (ulonglong)(param_1 & 0x3f);

    if (((*(byte *)((&DAT_1403ff160)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x38 + uVar2 * 0x48)

         & 1) != 0) &&

       (*(longlong *)

         ((&DAT_1403ff160)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x28 + uVar2 * 0x48) != -1)) {

      iVar1 = FUN_1402e7d34();

      if (iVar1 == 1) {

        if (param_1 == 0) {

          nStdHandle = 0xfffffff6;

        }

        else if (param_1 == 1) {

          nStdHandle = 0xfffffff5;

        }

        else {

          if (param_1 != 2) goto LAB_1402f4f54;

          nStdHandle = 0xfffffff4;

        }

        SetStdHandle(nStdHandle,(HANDLE)0x0);

      }

LAB_1402f4f54:

      *(undefined8 *)

       ((&DAT_1403ff160)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x28 + uVar2 * 0x48) =

           0xffffffffffffffff;

      return 0;

    }

  }

  puVar3 = (undefined4 *)FUN_1402e68b0();

  *puVar3 = 9;

  puVar3 = (undefined4 *)FUN_1402e688c();

  *puVar3 = 0;

  return 0xffffffff;

}




