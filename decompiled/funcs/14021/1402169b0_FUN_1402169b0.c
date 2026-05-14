// Address: 0x1402169b0
// Ghidra name: FUN_1402169b0
// ============ 0x1402169b0 FUN_1402169b0 (size=249) ============


undefined4 FUN_1402169b0(longlong param_1)



{

  longlong *plVar1;

  int iVar2;

  uint local_res8 [2];

  uint local_res10 [2];

  undefined4 local_res18 [4];

  

  iVar2 = FUN_140138fe0(param_1 + 0x8c);

  do {

    if (iVar2 != 0) {

      return 1;

    }

    local_res8[0] = 0;

    local_res10[0] = 0;

    local_res18[0] = 0;

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 8);

    (**(code **)(*plVar1 + 0x48))(plVar1,local_res8);

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 8);

    if ((local_res8[0] & 2) == 0) {

      if ((local_res8[0] & 1) == 0) {

        iVar2 = (**(code **)(*plVar1 + 0x60))(plVar1,0,0,1);

        if (iVar2 != 0) {

LAB_140216a44:

          if (iVar2 != -0x7787ff6a) {

            return 0;

          }

        }

      }

      else {

        iVar2 = (**(code **)(*plVar1 + 0x20))(plVar1,local_res18,local_res10);

        if (iVar2 != 0) goto LAB_140216a44;

        if (local_res10[0] / *(uint *)(param_1 + 0x6c) !=

            *(uint *)(*(longlong *)(param_1 + 200) + 0x24)) {

          return 1;

        }

      }

    }

    else {

      (**(code **)(*plVar1 + 0xa0))();

    }

    FUN_1401492f0(1);

    iVar2 = FUN_140138fe0(param_1 + 0x8c);

  } while( true );

}




