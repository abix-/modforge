// Address: 0x1401bf3d0
// Ghidra name: FUN_1401bf3d0
// ============ 0x1401bf3d0 FUN_1401bf3d0 (size=77) ============


longlong FUN_1401bf3d0(undefined8 param_1,longlong *param_2,char param_3)



{

  int iVar1;

  

  if (param_3 != '\0') {

    iVar1 = FUN_140138fe0(*param_2 + 0x30);

    if (0 < iVar1) {

      FUN_1401b8640(param_1,param_2);

    }

  }

  return *(longlong *)(**(longlong **)(*param_2 + 0x18) + 0x50) +

         (*(longlong **)(*param_2 + 0x18))[3];

}




