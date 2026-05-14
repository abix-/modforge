// Address: 0x14022c260
// Ghidra name: FUN_14022c260
// ============ 0x14022c260 FUN_14022c260 (size=215) ============


undefined8 FUN_14022c260(undefined8 param_1,longlong param_2,float param_3)



{

  HWND hWnd;

  uint uVar1;

  LONG LVar2;

  BOOL BVar3;

  undefined4 extraout_var;

  undefined4 extraout_var_00;

  undefined8 uVar4;

  undefined4 extraout_var_01;

  

  hWnd = *(HWND *)(*(longlong *)(param_2 + 0x188) + 8);

  uVar1 = GetWindowLongW(hWnd,-0x14);

  uVar4 = CONCAT44(extraout_var,uVar1);

  if (param_3 == DAT_14039ca44) {

    if ((uVar1 & 0x80000) != 0) {

      LVar2 = SetWindowLongW(hWnd,-0x14,uVar1 & 0xfff7ffff);

      uVar4 = CONCAT44(extraout_var_00,LVar2);

      if (LVar2 == 0) goto LAB_14022c2be;

    }

  }

  else {

    if (((uVar1 & 0x80000) == 0) && (LVar2 = SetWindowLongW(hWnd,-0x14,uVar1 | 0x80000), LVar2 == 0)

       ) {

LAB_14022c2be:

      uVar4 = FUN_1401a9ed0("SetWindowLong()");

      return uVar4;

    }

    BVar3 = SetLayeredWindowAttributes(hWnd,0,(BYTE)(int)(param_3 * DAT_14030a2d0),2);

    uVar4 = CONCAT44(extraout_var_01,BVar3);

    if (BVar3 == 0) {

      uVar4 = FUN_1401a9ed0("SetLayeredWindowAttributes()");

      return uVar4;

    }

  }

  return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);

}




