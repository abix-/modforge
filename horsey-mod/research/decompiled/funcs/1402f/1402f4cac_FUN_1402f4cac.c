// Address: 0x1402f4cac
// Ghidra name: FUN_1402f4cac
// ============ 0x1402f4cac FUN_1402f4cac (size=191) ============


undefined8 FUN_1402f4cac(uint param_1,HANDLE param_2)



{

  int iVar1;

  undefined4 *puVar2;

  DWORD nStdHandle;

  

  if ((-1 < (int)param_1) && (param_1 < DAT_1403ff560)) {

    if (*(longlong *)

         ((&DAT_1403ff160)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x28 +

         (ulonglong)(param_1 & 0x3f) * 0x48) == -1) {

      iVar1 = FUN_1402e7d34();

      if (iVar1 == 1) {

        if (param_1 == 0) {

          nStdHandle = 0xfffffff6;

        }

        else if (param_1 == 1) {

          nStdHandle = 0xfffffff5;

        }

        else {

          if (param_1 != 2) goto LAB_1402f4d2d;

          nStdHandle = 0xfffffff4;

        }

        SetStdHandle(nStdHandle,param_2);

      }

LAB_1402f4d2d:

      *(HANDLE *)

       ((&DAT_1403ff160)[(ulonglong)(longlong)(int)param_1 >> 6] + 0x28 +

       (ulonglong)(param_1 & 0x3f) * 0x48) = param_2;

      return 0;

    }

  }

  puVar2 = (undefined4 *)FUN_1402e68b0();

  *puVar2 = 9;

  puVar2 = (undefined4 *)FUN_1402e688c();

  *puVar2 = 0;

  return 0xffffffff;

}




