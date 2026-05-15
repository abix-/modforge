// Address: 0x140207460
// Ghidra name: FUN_140207460
// ============ 0x140207460 FUN_140207460 (size=530) ============


undefined8 FUN_140207460(void)



{

  char cVar1;

  longlong lVar2;

  undefined8 *puVar3;

  undefined8 *puVar4;

  undefined8 *puVar5;

  undefined2 local_res8 [4];

  undefined2 local_res10 [4];

  undefined4 local_78;

  undefined4 uStack_74;

  undefined4 uStack_70;

  undefined4 uStack_6c;

  char *local_68;

  undefined2 local_60;

  undefined2 local_5e;

  undefined8 local_5c;

  undefined8 local_54;

  undefined4 local_4c;

  wchar_t *local_48;

  wchar_t *local_40;

  undefined4 local_38;

  undefined4 local_34;

  undefined8 local_30;

  undefined4 local_28;

  undefined4 local_24;

  undefined8 local_20;

  

  puVar4 = (undefined8 *)0x0;

  _guard_check_icall();

  puVar5 = puVar4;

  puVar3 = DAT_1403fd198;

  if (DAT_1403e4e10 != '\0') {

    for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)puVar3[0x17]) {

      if (((puVar3[0xd] != 0) && (puVar3[0x14] == 0)) &&

         (*(char *)((longlong)puVar3 + 0x9a) == '\0')) {

        local_78 = *(undefined4 *)(puVar3 + 6);

        uStack_74 = *(undefined4 *)((longlong)puVar3 + 0x34);

        uStack_70 = *(undefined4 *)(puVar3 + 7);

        uStack_6c = *(undefined4 *)((longlong)puVar3 + 0x3c);

        FUN_1401582b0(&local_78,local_res10,local_res8,0,0);

        if ((puVar4 == (undefined8 *)0x0) &&

           ((cVar1 = FUN_140159550(local_res10[0],local_res8[0]), cVar1 != '\0' ||

            ((cVar1 = FUN_140159530(local_res10[0],local_res8[0]), cVar1 != '\0' &&

             (lVar2 = thunk_FUN_1402c9340(*puVar3,&DAT_140333508), lVar2 != 0)))))) {

          puVar4 = puVar3;

        }

        if ((puVar5 == (undefined8 *)0x0) &&

           ((cVar1 = FUN_1401595a0(local_res10[0],local_res8[0]), cVar1 != '\0' ||

            ((cVar1 = FUN_140159530(local_res10[0],local_res8[0]), cVar1 != '\0' &&

             (lVar2 = thunk_FUN_1402c9340(*puVar3,&DAT_14034fda8), lVar2 != 0)))))) {

          puVar5 = puVar3;

        }

        if ((puVar4 != (undefined8 *)0x0) && (puVar5 != (undefined8 *)0x0)) {

          puVar3 = (undefined8 *)FUN_1401841f0(0x10);

          if (puVar3 == (undefined8 *)0x0) {

            return 0;

          }

          *puVar3 = puVar4;

          puVar3[1] = puVar5;

          local_68 = "nintendo_joycons_combined";

          local_60 = 0x57e;

          local_5e = 0x2008;

          local_5c = 0;

          local_54 = 0;

          local_4c = 0;

          local_30 = 0;

          local_28 = 0;

          local_20 = 0;

          if (*(short *)((longlong)puVar4 + 0x22) != 0x2006) {

            local_5e = 0x2068;

          }

          local_34 = 0xffffffff;

          local_48 = L"Nintendo";

          local_40 = L"Switch Joy-Con (L/R)";

          local_38 = 0x50001;

          if ((*(char *)((longlong)puVar4 + 0x54) != '\0') ||

             (local_24 = 1, *(char *)((longlong)puVar5 + 0x54) != '\0')) {

            local_24 = 2;

          }

          lVar2 = FUN_140206f60(&local_68,2,puVar3);

          if (lVar2 != 0) {

            if (*(longlong *)(lVar2 + 0x68) == 0) {

              FUN_140207680(lVar2);

              return 0;

            }

            return 1;

          }

          FUN_1401841e0(puVar3);

          return 0;

        }

      }

    }

  }

  return 0;

}




