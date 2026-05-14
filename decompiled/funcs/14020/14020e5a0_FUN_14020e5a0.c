// Address: 0x14020e5a0
// Ghidra name: FUN_14020e5a0
// ============ 0x14020e5a0 FUN_14020e5a0 (size=252) ============


undefined4 FUN_14020e5a0(undefined8 *param_1,short param_2,short param_3)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  undefined4 local_res10 [4];

  longlong *local_res20;

  undefined8 local_18 [2];

  

  local_res10[0] = 0xffffffff;

  if ((param_2 == 0x28de) && (param_3 == 0x11ff)) {

    local_res20 = (longlong *)0x0;

    iVar1 = (**(code **)*param_1)(param_1,&DAT_140350608,&local_res20);

    if (-1 < iVar1) {

      iVar1 = (**(code **)(*local_res20 + 0x38))(local_res20,local_18);

      if (-1 < iVar1) {

        lVar2 = (*DAT_1403fd298)(local_18[0],0);

        if (lVar2 != 0) {

          lVar3 = FUN_14012fd40(lVar2);

          lVar2 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",lVar2,lVar3 * 2 + 2);

          if (lVar2 != 0) {

            FUN_14012ef30(lVar2,"{wgi/nrid/:steam-%*X&%*X&%*X#%d#%*u}",local_res10);

            FUN_1401841e0(lVar2);

          }

        }

        (*DAT_1403fd290)(local_18[0]);

      }

      (**(code **)(*local_res20 + 0x10))();

    }

    return local_res10[0];

  }

  return 0xffffffff;

}




