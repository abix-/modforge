// Address: 0x140180e30
// Ghidra name: FUN_140180e30
// ============ 0x140180e30 FUN_140180e30 (size=476) ============


undefined8 FUN_140180e30(undefined4 param_1,int *param_2,int *param_3)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  undefined8 uVar4;

  int iVar5;

  int iVar6;

  longlong *local_res10 [2];

  longlong *local_res20;

  undefined1 local_88 [96];

  

  lVar2 = FUN_14016dcf0();

  if (lVar2 == 0) {

    lVar2 = 0;

  }

  else {

    lVar2 = *(longlong *)(lVar2 + 0x680);

  }

  lVar3 = FUN_14016d390(param_1);

  if (param_2 == (int *)0x0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","adapterIndex");

    return uVar4;

  }

  if (param_3 == (int *)0x0) {

    uVar4 = FUN_14012e850("Parameter \'%s\' is invalid","outputIndex");

    return uVar4;

  }

  *param_2 = -1;

  *param_3 = -1;

  if (lVar3 != 0) {

    if ((lVar2 == 0) || (*(longlong *)(lVar2 + 0xf0) == 0)) {

      uVar4 = FUN_14012e850("Unable to create DXGI interface");

      return uVar4;

    }

    iVar6 = 0;

    iVar1 = *param_2;

    while( true ) {

      if (iVar1 != -1) {

        return 1;

      }

      iVar1 = (**(code **)(**(longlong **)(lVar2 + 0xf0) + 0x38))

                        (*(longlong **)(lVar2 + 0xf0),iVar6,&local_res20);

      if (iVar1 < 0) break;

      iVar5 = 0;

      iVar1 = *param_2;

      while ((iVar1 == -1 &&

             (iVar1 = (**(code **)(*local_res20 + 0x38))(local_res20,iVar5,local_res10), -1 < iVar1)

             )) {

        iVar1 = (**(code **)(*local_res10[0] + 0x38))(local_res10[0],local_88);

        if ((-1 < iVar1) && (iVar1 = FUN_14012fbc0(local_88,lVar3), iVar1 == 0)) {

          *param_2 = iVar6;

          *param_3 = iVar5;

        }

        (**(code **)(*local_res10[0] + 0x10))();

        iVar5 = iVar5 + 1;

        iVar1 = *param_2;

      }

      (**(code **)(*local_res20 + 0x10))();

      iVar6 = iVar6 + 1;

      iVar1 = *param_2;

    }

    if (*param_2 != -1) {

      return 1;

    }

    uVar4 = FUN_14012e850("Couldn\'t find matching adapter");

    return uVar4;

  }

  uVar4 = FUN_14012e850("Invalid display index");

  return uVar4;

}




