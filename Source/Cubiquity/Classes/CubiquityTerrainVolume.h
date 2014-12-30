// Copyright 2014 Volumes of Fun. All Rights Reserved.

#pragma once

#include "CubiquityVolume.h"

#include "CubiquityTerrainVolume.generated.h"

class UCubiquityMeshComponent;
class UCubiquityMaterialSet;

/**
*
*/
UCLASS()
class ACubiquityTerrainVolume : public ACubiquityVolume
{
	GENERATED_BODY()

public:

	ACubiquityTerrainVolume(const FObjectInitializer& PCIP);
	virtual void PostActorCreated() override;
	virtual void PostLoad() override;

	virtual void Destroyed() override;

	UFUNCTION(BlueprintCallable, Category = "Cubiquity")
	void sculptTerrain(FVector localPosition, float innerRadius = 0.5, float outerRadius = 2.0, float opacity = 0.8);

	UFUNCTION(BlueprintCallable, Category = "Cubiquity")
	FVector pickSurface(FVector localStartPosition, FVector localDirection);

	UFUNCTION(BlueprintCallable, Category = "Cubiquity")
	void setVoxel(FIntVector localPosition, const UCubiquityMaterialSet* materialSet);

	UFUNCTION(BlueprintCallable, Category = "Cubiquity")
	UCubiquityMaterialSet* getVoxel(FIntVector localPosition);

private:
	std::unique_ptr<Cubiquity::TerrainVolume> m_volume = nullptr;
	Cubiquity::Volume* volume() override { return m_volume.get(); }

	void loadVolume() override;
};
