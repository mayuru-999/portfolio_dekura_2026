using System.Collections.Generic;
using UnityEngine;

public class BallRegistry : MonoBehaviour
{
    public static readonly List<Transform> Balls = new List<Transform>();

    void OnEnable() { Balls.Add(transform); }
    void OnDisable() { Balls.Remove(transform); }
}