// Address: 0x1401c5e90
// Ghidra name: FUN_1401c5e90
// ============ 0x1401c5e90 FUN_1401c5e90 (size=813) ============


void FUN_1401c5e90(longlong param_1)



{

  uint uVar1;

  uint *puVar2;

  longlong *plVar3;

  undefined8 local_res8;

  undefined1 local_98 [128];

  

  puVar2 = *(uint **)(param_1 + 0x1d8);

  if (*(longlong *)(param_1 + 0x1e0) == 0) {

    FUN_1401cb360();

  }

  if (*(char *)(param_1 + 0x21f) != '\0') {

    uVar1 = *puVar2;

    if (uVar1 == 0) {

      *(undefined1 *)(param_1 + 0x21f) = 0;

    }

    else {

      FUN_1402f8e20(local_98,param_1 + 0x6b0,(ulonglong)uVar1 << 3);

      FUN_1401cbc70(param_1,1,local_98,uVar1,&local_res8);

      plVar3 = *(longlong **)(param_1 + 0x120);

      (**(code **)(*plVar3 + 0xf8))

                (plVar3,*(undefined4 *)(*(longlong *)(puVar2 + 8) + 8),local_res8);

      uVar1 = *puVar2;

      if (uVar1 != 0) {

        FUN_1402f8e20(local_98,param_1 + 0x630,(ulonglong)uVar1 << 3);

      }

      FUN_1401cbc70(param_1,0,local_98,uVar1,&local_res8);

      plVar3 = *(longlong **)(param_1 + 0x120);

      (**(code **)(*plVar3 + 0xf8))

                (plVar3,*(undefined4 *)(*(longlong *)(puVar2 + 8) + 0xc),local_res8);

      *(undefined1 *)(param_1 + 0x21f) = 0;

    }

  }

  if (*(char *)(param_1 + 0x220) != '\0') {

    uVar1 = puVar2[1];

    if (uVar1 != 0) {

      FUN_1402f8e20(local_98,param_1 + 0x730,(ulonglong)uVar1 << 3);

      FUN_1401cbc70(param_1,0,local_98,uVar1,&local_res8);

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0xf8))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar2 + 8) + 0x10),

                 local_res8);

    }

    *(undefined1 *)(param_1 + 0x220) = 0;

  }

  if (*(char *)(param_1 + 0x221) != '\0') {

    uVar1 = puVar2[2];

    if (uVar1 != 0) {

      FUN_1402f8e20(local_98,param_1 + 0x770,(ulonglong)uVar1 << 3);

      FUN_1401cbc70(param_1,0,local_98,uVar1,&local_res8);

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0xf8))

                (*(longlong **)(param_1 + 0x120),*(undefined4 *)(*(longlong *)(puVar2 + 8) + 0x14),

                 local_res8);

    }

    *(undefined1 *)(param_1 + 0x221) = 0;

  }

  if ((*(char *)(param_1 + 0x222) != '\0') && (puVar2[5] != 0)) {

    plVar3 = *(longlong **)(param_1 + 0x120);

    (**(code **)(*plVar3 + 0x128))

              (plVar3,*(undefined4 *)(*(longlong *)(puVar2 + 8) + 0x20),

               (ulonglong)*(uint *)((longlong)*(longlong **)(param_1 + 0x940) + 0xc) +

               *(longlong *)(**(longlong **)(param_1 + 0x940) + 0x78));

  }

  *(undefined1 *)(param_1 + 0x222) = 0;

  if ((*(char *)(param_1 + 0x223) != '\0') && (1 < puVar2[5])) {

    plVar3 = *(longlong **)(param_1 + 0x120);

    (**(code **)(*plVar3 + 0x128))

              (plVar3,*(undefined4 *)(*(longlong *)(puVar2 + 8) + 0x24),

               (ulonglong)*(uint *)((longlong)*(longlong **)(param_1 + 0x948) + 0xc) +

               *(longlong *)(**(longlong **)(param_1 + 0x948) + 0x78));

  }

  *(undefined1 *)(param_1 + 0x223) = 0;

  if ((*(char *)(param_1 + 0x224) != '\0') && (2 < puVar2[5])) {

    plVar3 = *(longlong **)(param_1 + 0x120);

    (**(code **)(*plVar3 + 0x128))

              (plVar3,*(undefined4 *)(*(longlong *)(puVar2 + 8) + 0x28),

               (ulonglong)*(uint *)((longlong)*(longlong **)(param_1 + 0x950) + 0xc) +

               *(longlong *)(**(longlong **)(param_1 + 0x950) + 0x78));

  }

  *(undefined1 *)(param_1 + 0x224) = 0;

  if ((*(char *)(param_1 + 0x225) != '\0') && (3 < puVar2[5])) {

    plVar3 = *(longlong **)(param_1 + 0x120);

    (**(code **)(*plVar3 + 0x128))

              (plVar3,*(undefined4 *)(*(longlong *)(puVar2 + 8) + 0x2c),

               (ulonglong)*(uint *)((longlong)*(longlong **)(param_1 + 0x958) + 0xc) +

               *(longlong *)(**(longlong **)(param_1 + 0x958) + 0x78));

  }

  *(undefined1 *)(param_1 + 0x225) = 0;

  return;

}




