// Address: 0x140131d50
// Ghidra name: FUN_140131d50
// ============ 0x140131d50 FUN_140131d50 (size=412) ============


longlong FUN_140131d50(undefined8 param_1,int *param_2)



{

  undefined8 uVar1;

  char cVar2;

  longlong lVar3;

  int *piVar4;

  longlong lVar5;

  int local_68;

  undefined4 uStack_64;

  undefined4 uStack_60;

  undefined4 uStack_5c;

  undefined8 local_58;

  undefined1 local_48 [64];

  

  lVar3 = FUN_140130ab0();

  if (lVar3 == 0) {

    return 0;

  }

  if (*(longlong *)(lVar3 + 0x1d0) == 0) {

    FUN_140139010(lVar3 + 0x1b8,0);

    *(undefined8 *)(lVar3 + 0x18) = DAT_1403fb5f8;

    *(undefined8 *)(lVar3 + 0x20) = DAT_1403fb600;

    *(undefined8 *)(lVar3 + 0x28) = DAT_1403fb608;

    FUN_140130440(lVar3,param_2,&local_68);

    cVar2 = (*DAT_1403fb5e8)(lVar3,&local_68);

    if (cVar2 != '\0') {

      piVar4 = &local_68;

      if (param_2 != (int *)0x0) {

        piVar4 = param_2;

      }

      uVar1 = *(undefined8 *)(piVar4 + 2);

      *(undefined8 *)(lVar3 + 0x54) = *(undefined8 *)piVar4;

      *(undefined8 *)(lVar3 + 0x5c) = uVar1;

      *(undefined8 *)(lVar3 + 100) = *(undefined8 *)(piVar4 + 4);

      *(int *)(lVar3 + 0x3c) = local_68;

      *(undefined4 *)(lVar3 + 0x40) = uStack_64;

      *(undefined4 *)(lVar3 + 0x44) = uStack_60;

      *(undefined4 *)(lVar3 + 0x48) = uStack_5c;

      *(undefined8 *)(lVar3 + 0x4c) = local_58;

      if ((local_68 == 0) || (cVar2 = FUN_140131ef0(lVar3), cVar2 != '\0')) {

        *(undefined4 *)(lVar3 + 0x78) = 1;

        if (DAT_1403fb620 == '\0') {

          FUN_140131c30(lVar3,local_48,0x40);

          lVar5 = FUN_140163260(FUN_1401303f0,local_48,lVar3,FUN_1402cfa08,FUN_1402cfae8);

          *(longlong *)(lVar3 + 0x1c0) = lVar5;

          if (lVar5 == 0) {

            FUN_1401307d0(lVar3);

            FUN_140130b70(lVar3);

            FUN_14012e850("Couldn\'t create camera thread");

            return 0;

          }

        }

        FUN_140130b60(lVar3);

        FUN_140130b70(lVar3);

        return lVar3;

      }

    }

    FUN_1401307d0(lVar3);

    FUN_140130b70(lVar3);

    return 0;

  }

  FUN_140130b70(lVar3);

  FUN_14012e850("Camera already opened");

  return 0;

}




