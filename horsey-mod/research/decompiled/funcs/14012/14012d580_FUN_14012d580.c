// Address: 0x14012d580
// Ghidra name: FUN_14012d580
// ============ 0x14012d580 FUN_14012d580 (size=144) ============


LARGE_INTEGER FUN_14012d580(undefined8 *param_1,LARGE_INTEGER param_2,int param_3)



{

  BOOL BVar1;

  LARGE_INTEGER LVar2;

  DWORD dwMoveMethod;

  LARGE_INTEGER local_res8 [4];

  

  if ((param_3 == 1) && (param_1[3] != 0)) {

    param_2.QuadPart = param_2.QuadPart - param_1[3];

    param_1[3] = 0;

  }

  else {

    dwMoveMethod = 0;

    param_1[3] = 0;

    if (param_3 == 0) goto LAB_14012d5a3;

    if (param_3 != 1) {

      if (param_3 != 2) {

        FUN_14012e850("windows_file_seek: Unknown value for \'whence\'");

        return (LARGE_INTEGER)-1;

      }

      dwMoveMethod = 2;

      goto LAB_14012d5a3;

    }

  }

  dwMoveMethod = 1;

LAB_14012d5a3:

  local_res8[0] = param_2;

  BVar1 = SetFilePointerEx((HANDLE)*param_1,param_2,local_res8,dwMoveMethod);

  if (BVar1 == 0) {

    LVar2._0_1_ = FUN_1401a9ed0("Error seeking in datastream");

    LVar2.QuadPart._1_7_ = 0;

    return (LARGE_INTEGER)LVar2.QuadPart;

  }

  return (LARGE_INTEGER)local_res8[0].QuadPart;

}




