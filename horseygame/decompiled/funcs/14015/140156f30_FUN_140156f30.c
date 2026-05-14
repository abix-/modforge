// Address: 0x140156f30
// Ghidra name: FUN_140156f30
// ============ 0x140156f30 FUN_140156f30 (size=333) ============


undefined8 FUN_140156f30(uint *param_1)



{

  longlong lVar1;

  undefined4 *puVar2;

  longlong lVar3;

  char cVar4;

  undefined8 uVar5;

  uint uVar6;

  undefined8 local_res8;

  

  uVar6 = *param_1;

  lVar1 = *(longlong *)(param_1 + 4);

  puVar2 = *(undefined4 **)(param_1 + 0x36);

  if (((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) &&

     ((uVar6 = uVar6 & 0xf000000, uVar6 == 0x1000000 ||

      (((uVar6 == 0xc000000 || (uVar6 == 0x2000000)) || (uVar6 == 0x3000000)))))) {

    if (puVar2 == (undefined4 *)0x0) {

      uVar5 = FUN_14012e850("Texture doesn\'t have a palette");

      return uVar5;

    }

    if (*(longlong *)(param_1 + 0x3e) == 0) {

      lVar3 = *(longlong *)(param_1 + 0x38);

      if (*(uint *)(lVar3 + 4) != puVar2[4]) {

        cVar4 = FUN_140149da0(lVar1,lVar3);

        if (cVar4 == '\0') {

          return 0;

        }

        cVar4 = (**(code **)(lVar1 + 0x78))(lVar1,lVar3,*puVar2,*(undefined8 *)(puVar2 + 2));

        if (cVar4 == '\0') {

          return 0;

        }

        *(undefined4 *)(lVar3 + 4) = puVar2[4];

      }

      *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(lVar1 + 600);

    }

    else if (param_1[0x3a] != puVar2[4]) {

      cVar4 = FUN_140149dc0();

      if ((cVar4 != '\0') &&

         (cVar4 = FUN_14014f7b0(*(undefined8 *)(param_1 + 0x3e),0,&local_res8), cVar4 != '\0')) {

        cVar4 = FUN_140144390(*(undefined8 *)(param_1 + 0x3c),0,local_res8,0);

        FUN_1401556c0(*(undefined8 *)(param_1 + 0x3e));

        if (cVar4 != '\0') {

          param_1[0x3a] = puVar2[4];

          return 1;

        }

      }

      return 0;

    }

  }

  return 1;

}




