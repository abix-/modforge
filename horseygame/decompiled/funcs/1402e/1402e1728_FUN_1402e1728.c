// Address: 0x1402e1728
// Ghidra name: FUN_1402e1728
// ============ 0x1402e1728 FUN_1402e1728 (size=156) ============


void FUN_1402e1728(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)



{

  uint uVar1;

  int iVar2;

  

  FUN_1402e1710(*param_2);

  if ((*(longlong *)*param_3 != 0) &&

     (uVar1 = *(uint *)(*(longlong *)*param_3 + 0x14), (uVar1 >> 0xd & 1) != 0)) {

    if (((((byte)uVar1 & 3) == 2) && ((uVar1 & 0xc0) != 0)) || ((uVar1 >> 0xb & 1) != 0)) {

      if ((*(char *)param_3[2] != '\0') || ((*(uint *)(*(longlong *)*param_3 + 0x14) >> 1 & 1) != 0)

         ) {

        iVar2 = FUN_1402e19d4(*(undefined8 *)*param_3);

        if (iVar2 == -1) {

          *(undefined4 *)param_3[3] = 0xffffffff;

        }

        else {

          *(int *)param_3[1] = *(int *)param_3[1] + 1;

        }

      }

    }

    else {

      *(int *)param_3[1] = *(int *)param_3[1] + 1;

    }

  }

  FUN_1402e171c(*param_4);

  return;

}




