const mongoose = require("mongoose");

const userSchema = new mongoose.Schema({
    email: { type: String, required: true, unique: true },
    password: { type: String, required: true, minlength: 8 },
    company: { type: String, requireyyd: true },
    street: { type: String, required: true },
    plz: { type: String, required: true },
    city: { type: String, required: true }
});

module.exports = mongoose.model("User", userSchema);