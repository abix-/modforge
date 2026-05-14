// Address: 0x140176dd0
// Ghidra name: FUN_140176dd0
// ============ 0x140176dd0 FUN_140176dd0 (size=165) ============


undefined8 FUN_140176dd0(int param_1,undefined8 *param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  if (param_1 != 0) {

    iVar1 = (**(code **)(PTR_PTR_1403e2870 + 8))();

    iVar3 = 0;

    if (0 < iVar1) {

      do {

        iVar2 = (**(code **)(PTR_PTR_1403e2870 + 0x30))(iVar3);

        if (iVar2 == param_1) {

          *param_2 = PTR_PTR_1403e2870;

          *param_3 = iVar3;

          return 1;

        }

        iVar3 = iVar3 + 1;

      } while (iVar3 < iVar1);

    }

  }

  FUN_14012e850("Sensor %u not found",param_1);

  return 0;

}




