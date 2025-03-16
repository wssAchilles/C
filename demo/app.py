from flask import Flask, jsonify, request
import random
from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # Enable CORS for all routes
# List of challenges
challenges = [
    {
        "id": 1,
        "title": "计算两个数的条件选择结果",
        "description": "给定两个整数 a 和 b，通过条件表达式计算结果。",
        "input": "int a = 20, b = 10; int max = (a > b && b < 0) ? a : b;",
        "output": "计算 max 的值。"
    },
    {
        "id": 2,
        "title": "8 位无符号二进制转十进制",
        "description": "将一个 8 位无符号二进制数 '10000011' 转换为十进制。",
        "input": "10000011",
        "output": "输出为十进制。"
    },
    {
        "id": 3,
        "title": "计算一个整数的各位数字之和",
        "description": "输入一个整数，计算并输出其各位数字之和。",
        "input": "示例输入: 1234",
        "output": "示例输出: 1 + 2 + 3 + 4 = 10"
    },
    {
        "id": 4,
        "title": "判断一个数是否为素数",
        "description": "输入一个正整数 n，判断它是否为素数。",
        "input": "示例输入: n = 17",
        "output": "示例输出: 是素数。"
    },
    {
        "id": 5,
        "title": "求最大公约数 (GCD)",
        "description": "输入两个整数，求其最大公约数。",
        "input": "示例输入: 36 60",
        "output": "示例输出: 最大公约数为 12"
    },
    {
        "id": 6,
        "title": "计算 1 到 n 的累加和",
        "description": "输入一个正整数 n，计算并输出从 1 到 n 的累加和。",
        "input": "示例输入: n = 5",
        "output": "示例输出: 1 + 2 + 3 + 4 + 5 = 15"
    },
    {
        "id": 7,
        "title": "5 个数中的最大值",
        "description": "输入 5 个整数，找出其中的最大值。",
        "input": "示例输入: 3 15 9 7 12",
        "output": "示例输出: 最大值是 15"
    },
    {
        "id": 8,
        "title": "求 n 的各位数字反转",
        "description": "输入一个正整数，输出它的各位数字的反转。",
        "input": "示例输入: 1234",
        "output": "示例输出: 4321"
    },
    {
        "id": 9,
        "title": "计算 n 的阶乘",
        "description": "输入一个整数 n，计算并输出它的阶乘。",
        "input": "示例输入: 5",
        "output": "示例输出: 5! = 120"
    },
    {
        "id": 10,
        "title": "斐波那契数列计算",
        "description": "根据递推关系定义斐波那契数列并计算第 n 项。",
        "input": "示例输入: n = 6",
        "output": "示例输出: F(6) = 8"
    },
    {
        "id": 11,
        "title": "倒三角形星号图案",
        "description": "输入一个正整数 n，输出一个倒三角形星号图案。",
        "input": "示例输入: n = 4",
        "output": "示例输出:\n****\n***\n**\n*"
    }
]

@app.route('/get-challenge', methods=['GET'])
def get_challenge():
    # Randomly select a challenge from the list
    challenge = random.choice(challenges)
    return jsonify(challenge)

if __name__ == '__main__':
    app.run(debug=True)
