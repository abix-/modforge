// Address: 0x14021b9a0
// Ghidra name: FUN_14021b9a0
// ============ 0x14021b9a0 FUN_14021b9a0 (size=345) ============


undefined8 FUN_14021b9a0(void)



{

  int iVar1;

  HRESULT HVar2;

  undefined8 uVar3;

  uint uVar4;

  uint local_res8 [2];

  undefined4 local_res10 [2];

  longlong *local_res18;

  longlong *local_res20;

  

  uVar4 = 0;

  local_res18 = (longlong *)0x0;

  iVar1 = FUN_1401a9610();

  if (iVar1 == 0) {

    DAT_1403fdb80 = 1;

  }

  HVar2 = CoCreateInstance((IID *)&DAT_1403552b8,(LPUNKNOWN)0x0,1,(IID *)&DAT_1403552c8,

                           &DAT_1403fdb88);

  if (-1 < HVar2) {

    iVar1 = (**(code **)(*DAT_1403fdb88 + 0x30))(DAT_1403fdb88,&PTR_PTR_1403e5408);

    if (iVar1 < 0) {

      (**(code **)(*DAT_1403fdb88 + 0x10))();

      DAT_1403fdb88 = (longlong *)0x0;

      uVar3 = FUN_1401a9ef0("Couldn\'t set the sensor manager event sink",iVar1);

      return uVar3;

    }

    iVar1 = (**(code **)(*DAT_1403fdb88 + 0x18))(DAT_1403fdb88,&DAT_140355240,&local_res18);

    if (-1 < iVar1) {

      iVar1 = (**(code **)(*local_res18 + 0x20))(local_res18,local_res8);

      if ((-1 < iVar1) && (local_res8[0] != 0)) {

        do {

          iVar1 = (**(code **)(*local_res18 + 0x18))(local_res18,uVar4,&local_res20);

          if (-1 < iVar1) {

            iVar1 = (**(code **)(*local_res20 + 0x60))(local_res20,local_res10);

            if (-1 < iVar1) {

              FUN_14021b5d0(&PTR_PTR_1403e5408,local_res20,local_res10[0]);

            }

            (**(code **)(*local_res20 + 0x10))();

          }

          uVar4 = uVar4 + 1;

        } while (uVar4 < local_res8[0]);

      }

      (**(code **)(*local_res18 + 0x10))();

    }

  }

  return 1;

}




