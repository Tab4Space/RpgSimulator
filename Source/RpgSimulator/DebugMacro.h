#pragma once

#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true);
#define DRAW_SPHERE_COLOR(Location, Color) DrawDebugSphere(GetWorld(), Location, 8.f, 12, Color, false, 5.f);
#define DRAW_SPHERE_SingleFrame(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, false, -1.f);
#define DRAW_LINE(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f);
#define DRAW_LINE_SingleFrame(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 1.f);
#define DRAW_POINT(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, true);
#define DRAW_POINT_SingleFrame(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, false, -1.f);
#define DRAW_VECTOR(StartLocation, EndLocation) if(GetWorld()) \
{	\
DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f);\
DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Red, true);\
}
#define DRAW_VECTOR_SingleFrame(StartLocation, EndLocation) if(GetWorld()) \
{	\
DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 1.f);\
DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Red, false, -1.f);\
}
#define DRAW_BOX(Center, Extent, Duration) if(GetWorld()) DrawDebugBox(GetWorld(), Center, Extent, FColor::Red, false, Duration, 0, 10.f);
#define DRAW_CONE(Location, Direction, Radius, AngleWidth, LifeTime) if(GetWorld()) DrawDebugCone(GetWorld(), Location, Direction, Radius, AngleWidth, FMath::DegreesToRadians(1.f), 32, FColor::Red, false, LifeTime, 0, 5);
#define DRAW_DONUT(Location, InnerRadius, OuterRadius, LifeTime) if(GetWorld()) \
{\
FTransform Transform{FRotator(90.0, 0.0, 0.0), Location, FVector(1.0, 1.0, 1.0)};\
DrawDebug2DDonut(GetWorld(), Transform.ToMatrixNoScale(), InnerRadius, OuterRadius, 50, FColor::Red, false, LifeTime, 0, 10.f);\
}
#define DRAW_CIRCLE(Location, Radius, Color, LifeTime) if(GetWorld()) DrawDebugCircle(GetWorld(), Location, Radius, 50, Color, false, 5.f, 0, 10.f, FVector(1, 0, 0), FVector(0, 1, 0), false);;
